//
// Created by oleg on 24.02.2021.
//

#include "Element.h"
int Element::get_data()const{
    return this->Data;
}
Element* Element::get_pNext()const{
    return this->pNext;
}
Element* Element::get_pPrev()const{
    return this->pPrev;
}
void Element::set_data(int Data){
    this->Data = Data;
}
Element::Element(int Data, Element* pPrev, Element* pNext): Data(Data), pPrev(pPrev), pNext(pNext){
    cout << "Element Constructor\t" << this << endl;
}
Element::~Element(){
    cout << "Element Destructor\t" << this << endl;
}
//operators
bool Element::operator == (Element* other){
    return (this == other);
}
bool Element::operator != (Element* other){
    return (this != other);
}
