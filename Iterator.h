//
// Created by oleg on 24.02.2021.
//

#ifndef OOP_CPP_ITERATOR_H
#define OOP_CPP_ITERATOR_H
#include <iostream>
#include "Element.h"
using namespace std;

class Iterator {
    Element* Temp;
public:
    Iterator(Element* pElement);
    Iterator(Iterator& other);
    Iterator(Iterator&& other);
    ~Iterator();
    bool operator==(const Iterator &other);
    bool operator!=(const Iterator &other);
    Iterator& operator++();
    Iterator operator++(int);
    int& operator*();
    Element* get_temp();
    friend class List;
    Iterator operator=(Iterator&& other);
};


#endif //OOP_CPP_ITERATOR_H
