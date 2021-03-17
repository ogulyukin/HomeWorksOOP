//
// Created by oleg on 16.03.2021.
//

#include "Iterator.h"
Iterator& Iterator::operator++(){
    Temp = Temp->pNext;
    return *this;
}
Iterator Iterator::operator++(int){
    Iterator old = *this;
    Temp = Temp->pNext;
    return old;
}
bool Iterator::operator==(const Iterator& other)const{
    return Temp == other.Temp;
}
bool Iterator::operator!=(const Iterator& other)const{
    return Temp != other.Temp;
}
ReverseIterator& ReverseIterator::operator++(){
    Temp = Temp->pPrev;
    return *this;
}
ReverseIterator ReverseIterator::operator++(int){
    ReverseIterator old = *this;
    Temp = Temp->pPrev;
    return old;
}
bool ReverseIterator::operator==(const ReverseIterator& other)const{
    return this->Temp == other.Temp;
}
bool ReverseIterator::operator!=(const ReverseIterator& other)const{
    return this->Temp != other.Temp;
}