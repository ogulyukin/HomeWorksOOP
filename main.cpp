#include <iostream>
#include "ForwardList.h"
#include "List.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    List<int> list = {2,54,23,34,67,890};
    list.print();
    List<double> list1 = {1.3,.9,34.5};
    list1.print();
    List<string> list2 = {"one", "two", "three", "Hello", "World!!!"};
    list2.print();
    ForwardList<int> list3 = {1,2,3,4,5,6,7,8,9};
    list3.print();
    ForwardList<double> list4 = {0.34, 87.4, 5.7,6.2};
    list4.print();
    return 0;
}
