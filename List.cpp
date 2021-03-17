//
// Created by oleg on 16.03.2021.
//

#include "List.h"
void List::push_back(int data){
    if(Tail == nullptr){
        Head = Tail = new Element(data, nullptr, nullptr);
        size++;
        return;
    }
    Tail = Tail->pNext = new Element(data, nullptr, Tail);
    size++;
}
void List::push_front(int data){
    if(Head == nullptr){
        Head = new Element(data, nullptr, nullptr);
        size++;
        return;
    }
    Head = Head->pPrev = Tail = new Element(data, Head, nullptr);
    size++;
}
void List::pop_back(){
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
void List::pop_front(){
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
void List::insert(int index, int value){
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
void List::Delete(int index){
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
Iterator List::begin(){return Head;}
Iterator List::end(){return nullptr;}
ReverseIterator List::rbegin(){return Tail;}
ReverseIterator List::rend(){return nullptr;}
void List::print()const{
    for(Iterator it = Head; it != nullptr; it++)
        cout << (*it) << "\t";
    cout << "\nSize: " << size << endl;
}
