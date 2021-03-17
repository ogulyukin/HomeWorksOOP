#include <iostream>
#include "List.h"

using namespace  std;
int main() {
    srand(time(0));
    List list = {12,35,67,12,15};
    list.print();
    list.insert(2,101);
    list.print();
    list.Delete(2);
    list.print();
    for(ReverseIterator rit = list.rbegin(); rit != list.rend(); rit++){
        cout << *rit << "\t";
    }
    return 0;
}
