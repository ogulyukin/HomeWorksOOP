//
// Created by oleg on 24.02.2021.
//
#pragma once
#ifndef OOP_CPP_LIST_H
#define OOP_CPP_LIST_H
#include <iostream>
#include "Element.h"
#include "Iterator.h"

class List {
    Element* Head;
    Element* Tail;
    int size;
public:
    //methods
    int get_size()const;
    Element* get_Head()const;
    Element* get_Head();
    Element* get_Tail()const;
    Element* get_Tail();
    void push_back(int Data);
    void push_front(int Data);
    void insert(int index, int Data);
    void pop_front();
    void pop_back();
    void erase(int index);
    void sort(Element* temp);
    void replace(Element* one, Element* two);
    //Constructors
    List();
    List(List& other);
    List(List&& other);
    List(int count);
    List(const initializer_list<int> &list);
    ~List();
    //operators
    List* operator=(List& other);
    List* operator=(List&& other);
    Element* operator[](int index);
};
List operator+(List& one, List& two);
ostream& operator<<(ostream& os, List& list);


#endif //OOP_CPP_LIST_H
