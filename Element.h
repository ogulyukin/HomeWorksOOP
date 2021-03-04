//
// Created by oleg on 24.02.2021.
//

#ifndef OOP_CPP_ELEMENT_H
#define OOP_CPP_ELEMENT_H
#include <iostream>

using namespace std;

class Element {
    int Data;
    Element* pPrev;
    Element* pNext;
public:
    int get_data()const;
    Element* get_pNext()const;
    Element* get_pPrev()const;
    void set_data(int Data);
    Element(int Data, Element* pPrev = nullptr, Element* pNext = nullptr);
    ~Element();
    //operators
    bool operator == (Element* other);
    bool operator != (Element* other);
    friend class List;
    friend class Iterator;
};


#endif //OOP_CPP_ELEMENT_H
