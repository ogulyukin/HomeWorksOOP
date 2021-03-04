//
// Created by oleg on 24.02.2021.
//

#include "Iterator.h"
Iterator::Iterator(Element* pElement): Temp(pElement){
    cout << "Iterator Constructor\t" << this << endl;
}
Iterator::Iterator(Iterator&& other){
    this->Temp = other.Temp;
    other.Temp = nullptr;
}
Iterator::Iterator(Iterator& other): Iterator(other.Temp){
}
Iterator::~Iterator(){
    cout << "Iterator Destructor\t" << this << endl;
}
bool Iterator::operator==(const Iterator &other){
    return (this->Temp == other.Temp);
}
bool Iterator::operator!=(const Iterator &other){
    return (this->Temp != other.Temp);
}
Iterator& Iterator::operator++(){
    Temp = Temp->pNext;
    return *this;
}
Iterator Iterator::operator++(int){
    Iterator old = *this;
    Temp = Temp->pNext;
    return old;
}
int& Iterator::operator*(){
    return Temp->Data;
}
Element* Iterator::get_temp(){
    return Temp;
}
Iterator Iterator::operator=(Iterator&& other){
    if(Temp)
        delete Temp;
    this->Temp = other.Temp;
    other.Temp = nullptr;
    return *this;
}