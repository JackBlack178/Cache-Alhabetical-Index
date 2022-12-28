//
// Created by Ilyas on 13.11.2021.
//

#ifndef LAB2_ELEMENT_H
#define LAB2_ELEMENT_H
#include <utility>

#include "string"
using std::string;

template <class K, class V>
class Element{
private:
 K key ;
 V value ;
public:
    Element(K newKey, V newValue){
        key = std::move(newKey);
        value = newValue;
    }

    Element() = default;

    K getKey(){
        return key;
    }

    V getValue(){
        return value;
    }


    int operator > (const Element set){
        return key < set.key;
    }

    int operator < (const Element set){
        return key > set.key;
    }

    int operator == (const Element set){
        return set.value == value and set.key == key;
    }

    friend std::ostream& operator<< (std::ostream &print, Element &el){
        return std::cout <<  "{ " << el.key << " : " << el.value << "} ";
    }

};




#endif //LAB2_ELEMENT_H
