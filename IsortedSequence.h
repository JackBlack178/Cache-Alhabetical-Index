//
// Created by Ilyas on 13.11.2021.
//

#ifndef LAB2_ISORTEDSEQUENCE_H
#define LAB2_ISORTEDSEQUENCE_H
#include "arraySequence.h"





template <typename T>
int cmp_default(T value1, T value2){
    return value1 < value2;
}


template <class T>
class IsortedSequence : private arraySequence<T>{

private:
    int (*comparer)(T value1, T value2) = cmp_default;


public:

   IsortedSequence() : arraySequence<T>(){

    };

    explicit IsortedSequence(int (*cmp)(T value1, T value2)) : arraySequence<T>(){
        comparer = cmp;
    };

    int getLength(){
        return this->arraySequence<T>::getLength();
    }

    int isEmpty(){
        return 0 == getLength();
    }

    T& get(int index){

        return this->arraySequence<T>::get(index);
    }

    int findIndex(T value){
        for (int i = 0; i < getLength(); i++){
            if (value == get(i))
                return i;
        }
        return -1;
    }

    T getFirst(){
        return get(0);
    }

    T getLast(){
        return get(getLength() - 1);
    }

    int index(T element){
        for (int i = 0; i < getLength(); i++){
            if (element == get(i))
                return i;
        }
        return -1;
    }


    void add(T value){
        if (getLength() == 0){
            this->arraySequence<T>::append(value);
            return;
        }

        for (int i = 0; i < getLength(); i++){
            if (comparer(value, get(i))){
                this->arraySequence<T>::insert(value, i);
                return;
            }
        }
        this->arraySequence<T>::append(value);

    }

    T pop(){
        return this->arraySequence<T>::pop(getLength() - 1);
    }

    T popByIndex(int index){
        return this->arraySequence<T>::pop(index);
    }



};

template <typename T>
std::ostream& operator << (std::ostream &print, IsortedSequence<T> &array){
    for (int i = 0; i < array.getLength(); i++){
        std::cout << array.get(i);
    }
    return std::cout << std::endl;
}


#endif //LAB2_ISORTEDSEQUENCE_H
