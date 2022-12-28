//
// Created by Ilyas on 13.12.2021.
//

#ifndef LAB2_DICTIONARY_H
#define LAB2_DICTIONARY_H
#include "IsortedSequence.h"
#include "Element.h"

template <class K, class V>
class Dictionary{
private:
    IsortedSequence<Element<K,V>>dictionary;



public:
    Dictionary() = default;

    V get(K key){
        for(int i = 0; i < dictionary.getLength();i++){
            if (dictionary.get(i).getKey() == key){
                return dictionary.get(i).getValue();
            }
        }
        throw ThereIsNoValueWithThisKey();
    }


    void add(Element<K,V>newElement){
        dictionary.add(newElement);
    }

    void remove(K key){

        for(int i = 0; i < dictionary.getLength();i++){
            if (getByIndex(i).getKey() == key){
                dictionary.pop(i);
                return;
            }
        }
        throw ThereIsNoValueWithThisKey();
    }


    int getCount(){
        return dictionary.getLength();
    }

    int containsKey(K key){
        for(int i = 0; i < dictionary.getLength();i++){
            if (dictionary.get(i).getKey() == key){
                return 1;
            }
        }
        return -1;
    }

    int findIndex(V value){
        for(int i = 0; i < dictionary.getLength();i++){
            if (dictionary.get(i).getValue() == value){
                return i;
            }
        }
        return -1;
    }


    friend std::ostream& operator << (std::ostream &print, Dictionary<K,V> &array){
        for (int i = 0; i < array.getCount(); i++){
            std::cout << array.dictionary.get(i) << std::endl;
        }
        return std::cout << std::endl;
    }

    void removeByIndex(int index) {
        dictionary.popByIndex(index);
    }


    Element<K,V> getByIndex(int index){
        return dictionary.get(index);
    }

};




#endif //LAB2_DICTIONARY_H
