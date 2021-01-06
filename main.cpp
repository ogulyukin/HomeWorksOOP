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
    cout << line << "THREE\n";
    binary three;
    cout << line;
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
    cout << line;
    cout << "Byte operators check:\nOperator NOT" << endl;
    cout << ~five << endl;
    cout << five.to_decimal() << endl;
    one = 102;
    cout << "Operator |" << endl;
    cout << one << "\t" << three << endl;
    cout << one.get_degree() << "\t" << three.get_degree() << endl;
    three.print();
    binary sixt = one | three;
    cout << sixt << endl;
    three.print();
    cout << one << "\t" << three << "END_HERE" << endl;
    cout << three << endl;
    cout << one.get_degree() << "\t" << three.get_degree() << endl;
    cout << "Operator &" << endl;
    cout << one << "\t" << three << endl;
    cout << (one & three) << endl;
    cout << "Operator ^" << endl;
    cout << one << "\t" << three << endl;
    cout << (one ^ three) << endl;
    binary seven;
    seven.binary_input();
    cout << seven << endl;
    cout << seven << endl;
    return 0;
}
