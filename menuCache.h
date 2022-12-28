//
// Created by Ilyas on 05.12.2021.
//

#ifndef LAB2_MENUCACHE_H
#define LAB2_MENUCACHE_H
#include "myCache.h"
#include "test.h"
#include "menuFunc.h"




struct Person{
    std::string name;
    int age{};
    std::string job;

    int operator == (const Person& otherPerson) const{
        return name == otherPerson.name and age == otherPerson.age and job == otherPerson.job;
    }

    friend std::ostream& operator<< (std::ostream &print, Person &person) {
        return std::cout << "Name - " << person.name << " Age - " << person.age << " Job - " << person.job;
    }

};


struct Person randomPerson(int lengthOfName = 24, int lengthOfJob = 24){
    struct Person person;
    person.name = randomString(lengthOfName);
    person.age = randomNumber() % 200;
    person.job = randomString(lengthOfJob);


    return person;
}

void printAction(Person person){
    std::cout << person << " was used" << std::endl;
}

void randomUseOfCacheContainsPerson(myCache<std::string, Person>&cache, int wishToPrintPerson){
    int randomNumberOfActions = randomLength() % cache.currentSize() / 4;
    for (int i = 0; i < randomNumberOfActions; i++){
        int randomIndex = randomNumber() % cache.currentSize();
        Person person = cache.getByIndex(randomIndex).getValue().getValue();
        std::string name = cache.getByIndex(randomIndex).getValue().getKey();
        cache.get(name);

        if (wishToPrintPerson)
            printAction(person);
    }
    std::cout << std::endl;
}

void randomAddPersonToCacheContainsPerson(myCache<std::string, Person>&cache, int numberOfAddingPerson = 1){
    for (int i = 0; i < numberOfAddingPerson; i++){
        struct Person person = randomPerson();
        cache.add(person,person.name);
    }
}


void menuCache(){
    std::cout << "Would you like to choose the size of cache?" << std::endl;
    std::cout << "Enter 1 - Yes" << std::endl;
    std::cout << "Enter 0 - No" << std::endl;
    int number = getNumberInRange(0,1);
    int cacheSize;
    if (number == 0)
        cacheSize = randomLength() % maxCacheSize;
    else{
        std::cout << "Enter cache size:";
        cacheSize = getNumberInRange(1,maxCacheSize);
    }

    myCache<std::string ,Person>cache(cacheSize);
    for (int i = 0; i < cacheSize; i++){
        Person person = randomPerson();
        std::string name = person.name;
        cache.add(person,name);
    }


    cache.printCache();
    std::cout << "Cache created" << std::endl;
    std::cout << "random use of elements" << std::endl;

    while(true){
        std::cout << "Print used person?" << std::endl;
        std::cout << "Enter 1 - Yes" << std::endl;
        std::cout << "Enter 0 - No" << std::endl;

        number = getNumberInRange(0,1);
        randomUseOfCacheContainsPerson(cache, number);

        std::cout << "Do you want to keep using cache?" << std::endl;
        std::cout << "Enter 1 - Yes" << std::endl;
        std::cout << "Enter 0 - No" << std::endl;
        number = getNumberInRange(0,1);
        if (not number)
            break;

        cache.printCache();
    }
    cache.printCache();
    std:: cout << "Adding other person to cache" << std::endl;
    while(true){
        randomAddPersonToCacheContainsPerson(cache);
        cache.printCache();
        std::cout << "Would you like to add one more person to cache" << std::endl;
        std::cout << "Enter 1 - Yes" << std::endl;
        std::cout << "Enter 0 - No" << std::endl;
        number = getNumberInRange(0,1);
        if (not number)
            break;
    }

    std::cout << "Launch again?" << std::endl;
    std::cout << "Enter 1 - Yes" << std::endl;
    std::cout << "Enter 0 - No" << std::endl;

    number = getNumberInRange(0,1);
    if (number)
        menuCache();
}

#endif //LAB2_MENUCACHE_H
