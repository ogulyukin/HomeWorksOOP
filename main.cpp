#include <iostream>
#include "List.h"

using namespace std;

int main() {
    srand(time(0));
    /*List list;
    cout << list << endl;
    list.push_front(10);
    cout << list << endl;
    list.push_front(15);
    cout << list << endl;
    list.push_back(20);
    cout << list << endl;
    List list2(3);
    cout << list2 << endl;
    list2.insert(2,101);
    cout << list2 << endl;
    list2.insert(2,102);
    cout << list2 << endl;
    list2.erase(3);
    cout << list2 << endl;*/
    List list2(4);
    cout << list2 << endl;
    List list3 = {2,8,101,1,20};
    cout << list3 << endl;
    List list4;
    list4 = list3 + list2;
    cout << list4 << endl;
    //cout << list4[4] << "\t" << list4[4]->get_data() << endl;
    list4.sort(list4.get_Tail());
    cout << list4 << endl;
    return 0;
}
