//
// Created by oleg on 17.03.2021.
//
#include <iostream>
#include <initializer_list>

using namespace std;
template <typename T> class ForwardList{
    class Element {
        T Data;
        Element* pNext;
    public:
        T get_Data()const;
        Element(T Data, Element* pNext = nullptr): Data(Data), pNext(pNext){}
        ~Element(){}
        friend class ForwardList;
        friend class Iterator;
    };
    class Iterator{
        Element* Temp;
    public:
        Iterator(Element* Temp): Temp(Temp){
            //cout << "Iterator constructor\t" << this << endl;
        }
        ~Iterator(){
            //cout << "Iterator destructor\t" << this << endl;
        }
        Iterator& operator++(){
            Temp = Temp->pNext;
            return *this;
        }
        Iterator operator++(int){
            Iterator old = *this;
            Temp = Temp->pNext;
            return old;
        }
        bool operator==(const Iterator& other){
            return (this->Temp == other.Temp);
        }
        bool operator!=(const Iterator& other){
            return (this->Temp != other.Temp);
        }
        T& operator*(){
            return Temp->Data;
        }
    };
    Element* Head;
    int size;
public:
    explicit ForwardList(int count): ForwardList(){
        if (count <= 0){
            cout << "Invalid quantity of elements!!!" << endl;
            Head = nullptr;
        }else {
            for (int i = 1; i < count; i++)
                push_back(0);
        }
    }
    ForwardList(const initializer_list<T> &list) : ForwardList(){
        for (T const* it = list.begin(); it != list.end(); it++){
            push_back(*it);
        }
    }
    ForwardList(const ForwardList &list): ForwardList(){
        Element* temp = list.Head;
        while(temp){
            this->push_back(temp->Data);
            temp = temp->pNext;
        };
    }
    ForwardList(ForwardList&& list){
        this->size = list.size;
        this->Head = list.Head;
        list.Head = nullptr;
    }
    ~ForwardList(){
        while(Head)
            pop_front();
    }
    Element* get_Head(){return Head;}
    int get_list_size()const{return size;}
    Iterator begin(){return Head;}
    Iterator end(){return nullptr;}
    ForwardList(){Head = nullptr; size = 0;}
    void print(){
        for (Iterator it = this->begin(); it != this->end(); it++)
            cout << (*it) << "\t";
        cout << "\nSize: " << this->size << endl;
    }
    void insert(int Index, T Data){
        if(Index < 0 || Index > size)
            throw exception();
        Element* Temp = Head;
        for (int i = 0; i < Index - 1; i++){
            Temp = Temp->pNext;
        }
        Temp->pNext = new Element(Data, Temp->pNext);
        size++;
    }
    void push_front(T data){
        Head = new Element(data, Head);
        size++;
    }
    void push_back(T data){
        if(Head == nullptr){
            push_front(data);
            return;
        }
        Element* Temp = Head;
        while(Temp->pNext != nullptr)
            Temp = Temp->pNext;
        Temp->pNext = new Element(data);
        size++;
    }
    void pop_front(){
        if (Head == nullptr)
            return;
        Element* temp = Head;
        Head = Head->pNext;
        delete temp;
        size--;
    }
    void pop_back(){
        if (Head == nullptr)
            return;
        Element* temp = Head;
        while (temp->pNext->pNext != nullptr){
            temp = temp->pNext;
        }
        delete temp->pNext;
        temp->pNext = nullptr;
        size--;
    }
    int get_size(){return size;}
    void Delete(int index){
        if(index < 0 || index > size)
            throw exception();
        Element* Temp = Head;
        for (int i = 0; i < index - 1; i++){
            Temp = Temp->pNext;
        }
        Element* Temp2 = Temp->pNext;
        Temp->pNext = Temp->pNext->pNext;
        delete Temp2;
        size--;

    }
};