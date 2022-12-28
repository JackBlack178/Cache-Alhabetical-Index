//
// Created by Ilyas on 13.11.2021.
//
#include "arraySequence.h"
#include "IsortedSequence.h"
#include "Element.h"
#include "dictionary.h"
#ifndef LAB2_MYCACHE_H
#define LAB2_MYCACHE_H



template <class K, class V>
class myCache{
private:
    int maxCacheSize = 10000;
    Dictionary<int,Element<K,V>> data;
public:
    explicit myCache(int maxSize){
        maxCacheSize = maxSize;

    }

    myCache() = default;

    int currentSize(){
        return data.getCount();
    }


    void add(V value, K key){
        if (currentSize() == maxCacheSize)
            data.removeByIndex(data.getCount() - 1);

        for (int i = 0; i < currentSize(); i++){

            if (value == data.getByIndex(i).getValue().getValue())
                return;
        }

        Element<int,Element<K,V>>newISet(1,Element<K,V>(key,value));
        data.add(newISet);
    }

    void freeCache(){                           //delete all elements in the cache
        for (int i = 0; i < data.getLength(); i++)
            data.removeByIndex(data.getCount());
    }

    V get(K key){
        int index;
        for(int i = 0; i < data.getCount(); i++){
            if (data.getByIndex(i).getValue().getKey() == key){
                index = i;
                break;
            }
        }
        int numberOfUses = data.getByIndex(index).getKey();
        V value = data.getByIndex(index).getValue().getValue();

        deleteElement(key);
        data.add(Element<int,Element<K,V>>(numberOfUses + 1, Element<K,V>(key,value)));
        return value;
    }


    Element<int,Element<K,V>> getByIndex(int index){
        return data.getByIndex(index);
    }


    void printCache(){
        std::cout << data;
    };

    void deleteElement(K key){
        for (int i = 0; i < data.getCount(); i++){
            if (data.getByIndex(i).getValue().getKey() == key)
                data.removeByIndex(i);
        }
    }

};


#endif //LAB2_MYCACHE_H
