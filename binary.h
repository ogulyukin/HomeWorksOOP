//
// Created by oleg on 04.01.2021.
//
#include <iostream>
#pragma once
using namespace std;
class binary;
ostream& operator<<(ostream& os, const binary& one);
istream& operator>>(istream& is, binary& one);
binary operator+(const binary& one, const binary& two);
binary operator-(const binary& one, const binary& two);
binary operator*(const binary& one, const binary& two);
binary operator/(const binary& one, const binary& two);
class binary{
    bool* binary_numbers;
    int degree;
public:
    void print()const;
    int get_degree()const;
    char* get_binary()const;
    void set_degree(int i);
    int to_decimal();
    int to_decimal()const;
    void set_binary(int number);
    binary& binary_input(); // this is reserved input method, butter use regular 'cin >>' instead
    binary(int number = 0);
    binary(const binary &other);
    ~binary();
    binary& operator=(const binary& other);
    binary& operator=(binary& other);
    binary& operator=(int number);
    bool operator==(const binary& other)const;
};