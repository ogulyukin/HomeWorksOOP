//
// Created by oleg on 16.03.2021.
//

#include "Element.h"
//
class Iterator{
    Element* Temp;
public:
    int& operator*(){return Temp->data;}
    Iterator& operator++();
    Iterator operator++(int);
    bool operator==(const Iterator& other)const;
    bool operator!=(const Iterator& other)const;
    Iterator(Element* Temp): Temp(Temp){}
    ~Iterator(){}
    friend class List;
};

class ReverseIterator {
    Element* Temp;
public:
    int& operator*(){return Temp->data;}
    ReverseIterator& operator++();
    ReverseIterator operator++(int);
    bool operator==(const ReverseIterator& other)const;
    bool operator!=(const ReverseIterator& other)const;
    ReverseIterator(Element* Temp): Temp(Temp){}
    ~ReverseIterator(){}
    friend class List;
};
