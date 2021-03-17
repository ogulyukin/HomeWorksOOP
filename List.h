//
// Created by oleg on 16.03.2021.
//
#pragma once
#include <iostream>
#include <initializer_list>
#include "Iterator.h"

using namespace std;

class List {
    Element* Head;
    Element* Tail;
    int size;
public:
    List(Element* Head = nullptr, Element* Tail = nullptr, int size = 0): Head(Head), Tail(Tail), size(size){}
    List(int size): List(){
        for (int i = 0; i < size; i++)
            push_back(0);
    }
    ~List(){
        while(Head){
            pop_back();
        }
    }
    List(const List& other): List(){
        Element* Temp = Head;
        for(Iterator it = other.Head; it != nullptr; it++){
            push_back(*it);
        }
    }
    List(List&& other){
        Head = other.Head;
        Tail = other.Tail;
        size = other.size;
        other.Head = other.Tail = nullptr;
        other.size = 0;
    }
    List(const initializer_list<int> &il): List(){
        for(int i: il)
            push_back(i);
    }
    Element* get_head(){return Head;}
    Element* get_tail(){return Tail;}
    //methods
    void push_back(int data);
    void push_front(int data);
    void pop_back();
    void pop_front();
    void insert(int index, int value);
    void Delete(int index);
    Iterator begin();
    Iterator end();
    ReverseIterator rbegin();
    ReverseIterator rend();
    void print()const;
};


