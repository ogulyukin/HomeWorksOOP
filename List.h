//
// Created by oleg on 17.03.2021.
//
#pragma once
#include <iostream>
#include <initializer_list>
using namespace std;
template <typename T> class List{
    class Element{
        T data;
        Element* pNext;
        Element* pPrev;
    public:
        int get_data(){return data;}
        Element(T data, Element* pNext = nullptr, Element* pPrev = nullptr) : data(data), pNext(pNext), pPrev(pPrev){}
        friend class List;
        friend class Iterator;
        friend class ReverseIterator;
    };
    class Iterator{
        Element* Temp;
    public:
        T& operator*(){return Temp->data;}
        Iterator& operator++(){
            Temp = Temp->pNext;
            return *this;
        }
        Iterator operator++(int){
            Iterator old = *this;
            Temp = Temp->pNext;
            return old;
        }
        bool operator==(const Iterator& other)const{return Temp == other.Temp;}
        bool operator!=(const Iterator& other)const{return Temp != other.Temp;}
        Iterator(Element* Temp): Temp(Temp){}
        ~Iterator(){}
        friend class List;
    };
    class ReverseIterator{
        Element* Temp;
    public:
        int& operator*(){return Temp->data;}
        ReverseIterator& operator++(){
            Temp = Temp->pPrev;
            return *this;
        }
        ReverseIterator operator++(int){
            ReverseIterator old = *this;
            Temp = Temp->pPrev;
            return old;
        }
        bool operator==(const ReverseIterator& other)const{return this->Temp == other.Temp;}
        bool operator!=(const ReverseIterator& other)const{return this->Temp != other.Temp;}
        ReverseIterator(Element* Temp): Temp(Temp){}
        ~ReverseIterator(){}
        friend class List;
    };
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
    List(const initializer_list<T> &il): List(){
        for(T i: il)
            push_back(i);
    }
    Element* get_head(){return Head;}
    Element* get_tail(){return Tail;}
    //methods
    void push_back(T data){
        if(Tail == nullptr){
            Head = Tail = new Element(data, nullptr, nullptr);
            size++;
            return;
        }
        Tail = Tail->pNext = new Element(data, nullptr, Tail);
        size++;
    }
    void push_front(T data){
        if(Head == nullptr){
            Head = new Element(data, nullptr, nullptr);
            size++;
            return;
        }
        Head = Head->pPrev = Tail = new Element(data, Head, nullptr);
        size++;
    }
    void pop_back(){
        if(Tail == nullptr)
            return;
        if(Tail->pPrev == nullptr){
            delete Tail;
            Tail = Head = nullptr;
        }else{
            Tail = Tail->pPrev;
            delete Tail->pNext;
            Tail->pNext = nullptr;
        }
        size--;
    }
    void pop_front(){
        if(Head == nullptr)
            return;
        if(Head->pNext == nullptr){
            delete Head;
            Head = Tail = nullptr;
        }else{
            Head = Head->pNext;
            delete Head->pPrev;
            Head->pPrev = nullptr;
        }
        size--;
    }
    void insert(int index, T value){
        if(index < 0 || index > size)
            throw exception();
        Element* Temp;
        if (index == 0){
            push_front(value);
        }else if(index < size / 2){
            Temp = Head;
            for (int i = 0; i <= index; i++){
                Temp = Temp->pNext;
            }
        }else{
            Temp = Tail;
            for(int i = 1; i != size - index - 1; i++){
                Temp = Temp->pPrev;
            }
        }
        Temp->pPrev = Temp->pPrev->pNext = new Element(value,Temp, Temp->pPrev);
        size++;
    }
    void Delete(int index){
        if(index < 0 || index > size)
            throw exception();
        Element* Temp;
        if(index < size / 2){
            Temp = Head;
            for (int i = 0; i <= index; i++){
                Temp = Temp->pNext;
            }
        }else{
            Temp = Tail;
            for(int i = 1; i != size - index - 1; i++){
                Temp = Temp->pPrev;
            }
        }
        Temp->pPrev->pNext = Temp->pNext;
        Temp->pNext->pPrev = Temp->pPrev;
        delete Temp;
        size--;
    }
    Iterator begin(){return Head;}
    Iterator end(){return nullptr;}
    ReverseIterator rbegin(){return Tail;}
    ReverseIterator rend(){return nullptr;}
    void print()const{
        for(Iterator it = Head; it != nullptr; it++)
            cout << (*it) << "\t";
        cout << "\nSize: " << size << endl;
    }
};