#include <iostream>
#include "string.h"
using namespace std;
class myString{
    int size;
    char *mystring;
public:
    int get_size()const{
        return this->size;
    }
    char* get_mystring()const{
        return this->mystring;
    }
    //Constructors
    myString(){
        this->size = 256;
        this->mystring = new char[size];
        strcat(this->mystring, "Default string");
    }
    myString(char string[]){
        this->size = strlen(string)+1;
        this->mystring = new char[size]{};
        for (int i = 0 ; i<size; i++){
            this->mystring[i] = string[i];
        }
    }
    myString(char string[], int size){
        this->mystring =  new char[size]{};
        this->size = size;
        for (int i = 0 ; i<size; i++){
            this->mystring[i] = string[i];
        }
    }
    myString(string mstring){
        this->size = mstring.length();
        const char* temp = mstring.c_str();
        this->mystring = new char[size]{};
        strcpy(this->mystring, temp);
    }
    ~myString(){
        delete [] mystring;
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
    cout << "Checking second conctructor new string will contains 10 symbols:" << endl;
    int size = 11;
    char* input02 = new char[size]{};
    InputLine(input02,size);
    myString example02(input02, strlen(input02));
    cout << "Let see what we get inside the Class, now:" << endl;
    cout << example02.get_mystring() << "\t" << example02.get_size() << endl;
    delete [] input02;
    cout << "Checking third conctructor, Let it be \"Third one\":" << endl;
    string input03 = "Third one";
    myString example03(input03);
    cout << "Let see what we get inside the Class this time:" << endl;
    cout << example03.get_mystring() << "\t" << example03.get_size() << endl;
    myString default_str;
    cout << "And the last - check default constructor:" << endl;
    cout << default_str.get_size() << "\t" << default_str.get_mystring() << endl;
    return 0;
}
void InputLine(char str[], const int n){
    //SetConsoleCP(1251);
    cin.ignore(32767, '\n');
    cout << "Now enter string : "; cin.getline(str,n);//cin >> str;
    //SetConsoleCP(866);
}
