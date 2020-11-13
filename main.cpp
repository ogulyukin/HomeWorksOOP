#include <iostream>
#include "string.h"
using namespace std;
class myString{
    int size;
    char *mystring;
public:
    int get_size(){
        return this->size;
    }
    char* get_mystring(){
        return this->mystring;
    }
    //Constructors
    myString(char string[]){
        this->size = strlen(string);
        this->mystring = string;
    }
    myString(char string[], int size){
        this->mystring = string;
        this->size = size;
    }
    myString(string mstring){
        this->size = mstring.length();
        cout << this->size << endl;
        const char* temp = mstring.c_str();
        cout << temp << endl;
        strcpy(this->mystring, temp);
        cout << this->mystring << endl;
    }
    ~myString(){

    }
};
void InputLine(char str[], const int n);
int main() {
    setlocale(LC_ALL, "");
    cout << "Checking first conctructor, Enter string. Any..." << endl;
    char input01[256]{};
    cin >> input01;
    myString example01(input01);
    cout << "Let see what we get inside the Class:" << endl;
    cout << example01.get_mystring() << "\t" << example01.get_size() << endl;
    cout << "Checking second conctructor, Enter lengh of future string:" << endl;
    int size = 0;
    cin.ignore(32767, '\n');
    cin >> size;
    char* input02 = new char[size];
    InputLine(input02,size);
    input02[size] = 0;
    myString example02(input02, strlen(input02));
    cout << "Let see what we get inside the Class, now:" << endl;
    cout << example02.get_mystring() << "\t" << example02.get_size() << endl;
    delete [] input02;
    cout << "Checking third conctructor, Enter string. Any again..." << endl;
    string input03;
    cin.ignore(32767, '\n');
    cin >> input03;
    cout << "input03 " << input03 << endl;
    myString example03(input03);
    cout << "Let see what we get inside the Class this time:" << endl;
    cout << example03.get_mystring() << "\t" << example03.get_size() << endl;
    return 0;
}
void InputLine(char str[], const int n){
    //SetConsoleCP(1251);
    cin.ignore(32767, '\n');
    cout << "Now enter string : "; cin.get(str,n);//cin >> str;
    //SetConsoleCP(866);
}
