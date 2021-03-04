//
// Created by oleg on 24.02.2021.
//

#include "List.h"
#include <initializer_list>
//Constructors
List::List(): Head(nullptr), Tail(nullptr), size(0){
    cout << "List Constructor\t" << this << endl;
}
List::List(const initializer_list<int> &list): List(){
    Element* temp = Head;
    for(int i:list){
        push_back(i);
        temp->pNext;
    }
}
List::List(int count): List() {
    while(count > 0){
        push_front(rand()%100);
        system("sleep 1");
        count--;
    }
}
List::List(List& other): List(){
    Element* temp = other.Head;
    while (temp){
        push_back(temp->Data);
        temp = temp->pNext;
    }
    cout << "List Copy Constructor\t" << this << endl;
}
List::List(List&& other){
    while(Head != nullptr)
            pop_front();
    this->Head = other.Head;
    this->Tail = other.Tail;
    this->size = other.size;
    other.Head = nullptr;
    other.Tail = nullptr;
    cout << "List Move Constructor\t" << this << endl;
}
List::~List(){
    while(Head != nullptr){
        pop_front();
    }
    cout << "List Destructor\t" << this << endl;
}
//methods
int List::get_size()const{
    return this->size;
}
Element* List::get_Head()const{
    return Head;
}
Element* List::get_Head(){
    return Head;
}
Element* List::get_Tail()const{
    return Tail;
}
Element* List::get_Tail(){
    return Tail;
}
void List::push_back(int Data){
    if (size == 0){
        push_front(Data);
        return;
    }
    Tail = new Element(Data, Tail, nullptr);
    Tail->pPrev->pNext = Tail;
    //cout << "PushBack\t" << Tail->Data << " pPrev: " << Tail->pPrev << " pNext: " << Tail->pNext << endl;
    size++;
}
void List::push_front(int Data){
    Head = new Element(Data, nullptr, Head);
    if(size == 0){
        Tail = Head;
    }else{
        Head->pNext->pPrev = Head;
    }
    size++;
    //cout << "PushFront\t" << Head->Data << " pPrev: " << Head->pPrev << " pNext: " << Head->pNext << endl;
}
void List::insert(int index, int Data){
    if (index == size - 1){
        push_back(Data);
        return;
    }
    if(index == 0){
        push_front(Data);
        return;
    }
    Element* temp = Head;
    for(int i = 0; i < index; i++){
        if(temp->pNext == nullptr)
            throw exception();
        temp = temp->pNext;
    }
    Element* result = new Element(Data, temp->pPrev, temp);
    temp->pPrev->pNext = result;
    temp->pPrev = result;
    size++;
}
void List::pop_front(){
    if (size == 0)
        return;
    if(size == 2){
        delete Head;
        Head = Tail;
        size--;
        return;
    }
    if(size == 1){
        delete Head;
        Head = nullptr;
        Tail = nullptr;
        size--;
        return;
    }
    Element* temp = Head;
    Head = Head->pNext;
    delete temp;
    size--;
}
void List::pop_back(){
    if(Tail == nullptr)
        return;
    if(Tail->pPrev == nullptr){
        pop_front();
        return;
    }
    Element* temp = Tail;
    Tail = Tail->pPrev;
    delete temp;
    size--;
}
void List::erase(int index){
    if (index == 0){
        pop_front();
        return;
    }
    if (index == size - 1){
        pop_back();
        return;
    }
    Element* temp = Head;
    while(index > 0){
        if (temp->pNext == nullptr)
            throw exception();
        temp = temp->pNext;
        index--;
    }
    temp->pPrev->pNext = temp->pNext;
    delete temp;
    size--;
}
List* List::operator=(List& other){
    while(this->Head)
        pop_front();
    for(Iterator i(other.Head);i != nullptr ;++i)
        this->push_back(*i);
    //this->push_back(other.Tail->Data);
    cout << "List Copy Assigment\t" << this << endl;
    return this;
}
List* List::operator=(List&& other){
    while (this->Head)
        pop_front();
    this->Head = other.Head;
    this->Tail = other.Tail;
    this->size = other.size;
    other.Head = nullptr;
    other.Tail = nullptr;
    cout << "List Move Assigment\t" << this << endl;
    return this;
}
Element* List::operator[](int index){
    if(index < 0 || index > size)
        throw exception();
    Iterator it = this->Head;
    for(int i = 0; i < index; i++){
        it++;
    }
    return it.get_temp();
}
ostream& operator<<(ostream& os, List& list){
    Element* temp = list.get_Head();
    os << "Head: " << list.get_Head() << endl;
    os << "Tail: " << list.get_Tail() << endl;
    os << "Size is: " << list.get_size() << endl;
    while(temp != nullptr){
        os << temp->get_data() << "\t";
        temp = temp->get_pNext();
    }
    return os;
}
List operator+(List& one, List& two){
    List result = one;
    for (Iterator i = two.get_Head(); i != nullptr; i ++)
        result.push_back(*i);
    //result.push_back(two.get_Tail()->get_data());
    return result;
}
void List::sort(Element* temp){
    if (!temp->pPrev)
        return;
    for(Iterator i(Head); i != temp; i++){
        if(i.Temp->Data > i.Temp->pNext->Data)
            replace(i.Temp, i.Temp->pNext);
    }
    temp = temp->pPrev;
    sort(temp);
}
void List::replace(Element* one, Element* two){
    int temp = one->Data;
    one->Data = two->Data;
    two->Data = temp;
}