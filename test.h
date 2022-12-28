//
// Created by Ilyas on 02.12.2021.
//

#ifndef LAB2_TEST_H
#define LAB2_TEST_H
#include "IsortedSequence.h"
#include "myCache.h"
#include "Element.h"
#include "menuFunc.h"



template <typename T>
void printSortedSequence(IsortedSequence<T>Isort){
    for (int i = 0; i < Isort.getLength(); i++){
        std::cout << Isort.get(i) << " ";
    }
}

void IsortedSequenceAddTest(int number){
    IsortedSequence<int>Isort;
    int errors = 0;
    for (int i = 0; i < number; i++){
        int length = randomLength();
        for (int j = 0; j < length; j++){
           Isort.add(randomNumber());
       }

        for (int j = 0; j < length - 1; j++){
            if (Isort.get(j) > Isort.get(j+1))
                errors++;
        }
    }
    std::cout << errors << " errors were revealed" << std::endl;
}

void IsortedSequenceFindTest(int number){
    IsortedSequence<int>Isort;
    int errors = 0;
    for (int i = 0; i < number; i++){
        int length = randomLength();
        for (int j = 0; j < length; j++){
            Isort.add(randomNumber());
        }

        int randomIndex = rand() % (length-1);
        int value = Isort.get(randomIndex);
        if (randomIndex != Isort.findIndex(value)){
            errors++;
        }
    }
    std::cout << std::endl;
    std::cout << errors << " errors were revealed" << std::endl;
}

//void testCache(int number){
//    myCache<int>cache;
//    int errors = 0;
//    int testValue;
//    for (int i = 0; i < number; i++){
//        int length = randomLength();
//        for (int j = 0; j < length; j++){
//            testValue = randomNumber();
//            cache.add(testValue);
//        }
//        int index = cache.findIndex(testValue);
//        cache.get(index);
//        if (index == cache.findIndex(testValue))
//            errors++;
//
//    }
//    std::cout << std::endl;
//    std::cout << errors << " errors were revealed" << std::endl;
//}






void IsortedSequenceTest(int number){
    IsortedSequenceAddTest(number);
    IsortedSequenceFindTest(number);
}

#endif //LAB2_TEST_H
