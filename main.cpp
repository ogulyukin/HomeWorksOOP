#include <iostream>
#include "string.h"
using namespace std;
using std::ostream;
class String;
String operator+(String &one, String &two);
void operator+=(String &one, String &two);
ostream& operator<<(ostream& ist, String &one);
class String{
    int size;
    char* str;
public:
    int get_size()const{
        return size;
    }
    const char* get_str()const{
        return str;
    }
    String(int size = 80){
        this->size = size;
        this->str = new char[size]{};
        cout << "Default Constructor\t" << this << endl;
    }
    String(const char str[]){
        this->size =  strlen(str);
        this->str = new char[size];
        for (int i = 0; str[i]; i++){
            this->str[i] = str[i];
        }
        cout << "String Constructor\t" << this << endl;
    }
    String(const String& other){
        this->size =  other.size;
        this->str = new char[size]{};
        for (int i = 0; other.str[i]; i++){
            this->str[i] = other.str[i];
        }
        cout << "Copy Constructor\t" << this << endl;
    }
    ~String(){
        delete[] str;
        cout << "Destructor\t" << this << endl;
    }
    //      Methods
    void print()const{
        cout << "Size  :\t" << size << endl;
        cout << "String:\t" << str << endl;
    }
    //operators
    String& operator=(const String& other){
        this->size = other.size;
        delete []this->str;
        this->str = new char[size]{};
        for (int i = 0; i < size; i++){
            this->str[i] = other.str[i];
        }
        cout << "Move assigment constrictor" << endl;
        return *this;
    }
    char operator[](int i)const{
        return str[i];
    }
};
int main() {
    setlocale(LC_ALL, "");
    String str01 = "World!";
    str01.print();
    String str02 = "Hello!";
    str02.print();
    String str03("TEST");
    cout << str03 << endl;
    String str04(str01);
    cout << str04 << endl;
    str04 = str01 + str02;
    cout << str04 << endl;
    str04 += str03;
    cout << str04 << endl;
    //str02 = str02;
    //str03.print();
    return 0;
}
String operator+(String &one, String &two){
    char* newstr = new char[one.get_size()+two.get_size()]{};
    for(int i = 0; i < one.get_size(); i++){
        newstr[i] = one[i];
    }
    for(int i = 0; i < two.get_size(); i++){
        newstr[i + one.get_size()] = two[i];
    }
    String result(newstr);
    delete []newstr;
    return result;
}
void operator+=(String &one, String &two){
    one = one + two;
}
ostream& operator<<(ostream& ist, String &one){
    one.print();
    return ist;
}
