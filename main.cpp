#include <iostream>
#include "binary.h"
using namespace std;
#define line "_____________________________\n"

int main() {
    binary one(100);
    cout << one << endl;
    cout << one.to_decimal() << endl;
    cout << line;
    binary two = one;
    cout << line;
    cout << two << endl;
    binary three;
    three = 2;
    cout << three << endl;
    cout << line;
    cout << "Enter any decimal number : "; cin >> three;
    cout << three << endl;
    cout << line;
    binary five;
    cout << one.to_decimal() << "\t" << three.to_decimal() << endl;
    cout << "Operators check +" << endl;
    cout << (five = one + three) << endl;
    cout << five.to_decimal() << endl;
    cout << "Operators check -" << endl;
    cout << (five = one - three) << endl;
    cout << five.to_decimal() << endl;
    cout << "Operators check *" << endl;
    cout << (five = one * three) << endl;
    cout << five.to_decimal() << endl;
    cout << "Operators check /" << endl;
    cout << (five = one / three) << endl;
    cout << five.to_decimal() << endl;
    return 0;
}
