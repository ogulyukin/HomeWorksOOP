//
// Created by oleg on 04.01.2021.
//
#include "binary.h"
#include "math.h"
void binary::print()const{
    cout << get_binary() << endl;
}
int binary::get_degree()const{
    return this->degree;
}
char* binary::get_binary()const{
    char* result = new char[this->degree]{};
    for (int i = 0; i <= this->degree; i++){
        if (this->binary_numbers[i]){
            result[i] = '1';
        }else{
            result[i] = '0';
        }
    }
    return result;
}
void binary::set_degree(int i){
    int result = 0, div_result;
    do{
        div_result = i % 2;
        i = i / 2;
        result++;
    } while (i > 1);
    this->degree = result;
}
int binary::to_decimal(){
    int result = 0, degree = 0;
    for (int i = this->degree; i >= 0; i-- ){
        (this->binary_numbers[i]) ? (result += pow(2, degree)) : (0);
        degree++;
    }
    return result;
}
int binary::to_decimal()const{
    int result = 0, degree = 0;
    for (int i = this->degree; i >= 0; i-- ){
        (this->binary_numbers[i]) ? (result += pow(2, degree)) : (0);
        degree++;
    }
    return result;
}
void binary::set_binary(int number){
    this->binary_numbers = new bool [this->degree];
    for (int i = this->degree; i >= 0; i-- ){
        (number%2) ? (this->binary_numbers[i] = true) : (this->binary_numbers[i] = false);
        number /= 2;
    }
}
binary& binary::binary_input(){
    int input = 0;
    cout << "Enter any decimal number: ";cin >> input;
    *this = input;
    return *this;
}
binary::binary(int number){
    set_degree(number);
    set_binary(number);
    cout << "Default constructor " << this << endl;
}
binary::binary(const binary &other):binary(other.to_decimal()){
    cout << "Copy constructor " << this << endl;
}
binary::~binary(){
    delete[] binary_numbers;
    cout << "Destructor " << this << endl;
}
binary& binary::operator=(const binary& other){
    if (this == &other)
        return *this;
    delete[] this->binary_numbers;
    this->degree = other.degree;
    this->set_binary(other.to_decimal());
    cout << "Copy assigiment const " << this << endl;
    return *this;
}
binary& binary::operator=(binary& other){
    if (this == &other)
        return *this;
    delete[] this->binary_numbers;
    this->degree = other.degree;
    this->set_binary(other.to_decimal());
    cout << "Copy assigiment " << this << endl;
    return *this;
}
binary& binary::operator=(int number){
    delete[] this->binary_numbers;
    this->set_degree(number);
    this->set_binary(number);
    cout << "Copy assigiment int " << this << endl;
    return *this;
}
bool binary::operator==(const binary& other)const{
    if (this->to_decimal() == other.to_decimal())
        return true;
    return false;
}
ostream& operator<<(ostream& os, const binary& one){
    os << one.get_binary();
    return os;
}
istream& operator>>(istream& is, binary& one){
    int inpt;
    is >> inpt;
    one = inpt;
    return is;
}
binary operator+(const binary& one, const binary& two){
    binary result(int(one.to_decimal() + two.to_decimal()));
    //cout << "inside" << int(one.to_decimal() + two.to_decimal()) << endl;
    return result;
}
binary operator-(const binary& one, const binary& two){
    binary result(one.to_decimal() - two.to_decimal());
    return result;
}
binary operator*(const binary& one, const binary& two){
    binary result(one.to_decimal() * two.to_decimal());
    return result;
}
binary operator/(const binary& one, const binary& two){
    if (two.to_decimal() == 0){
        cout << "ERROR Divining zero found!!!" << endl;
        return 0;
    }
    binary result(one.to_decimal() / two.to_decimal());
    return result;
}
