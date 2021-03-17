//
// Created by oleg on 16.03.2021.
//

class Element {
    int data;
    Element* pNext;
    Element* pPrev;
public:
    int get_data(){return data;}
    Element(int data, Element* pNext = nullptr, Element* pPrev = nullptr) : data(data), pNext(pNext), pPrev(pPrev){}
    friend class List;
    friend class Iterator;
    friend class ReverseIterator;
};
