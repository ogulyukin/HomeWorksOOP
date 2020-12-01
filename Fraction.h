//
// Created by oleg on 30.11.2020.
//

#ifndef HOMEWORKSOOP_FRACTION_H
#define HOMEWORKSOOP_FRACTION_H
#pragma once
using namespace std;
class Fraction{
    int integer;
    int numerator;
    int denumenator;
    void check_if_negative(){
        if (denumenator < 0){
            denumenator *= -1;
            numerator *= -1;
        }
        if (integer < 0 && numerator < 0){
            numerator *= -1;
        }
        if(integer > 0 && numerator < 0){
            numerator *= -1;
            integer *= -1;
        }
    }
public:
    //get / set methods:
    int get_integer()const{
        return this->integer;
    }
    int get_numerator()const{
        return this->numerator;
    }
    int get_denumenator()const{
        return this->denumenator;
    }
    void set_integer(int integer){
        this->integer = integer;
    }
    void set_numerator(int numerator){
        this->numerator = numerator;
    }
    void set_denumenator(int denumenator){
        (denumenator)?(this->denumenator = denumenator):(this->denumenator = 1);
    }
    //methods:
    Fraction& to_proper(){
        this->integer += numerator / denumenator;
        set_numerator(get_numerator()%get_denumenator());
        if (!numerator)
            set_denumenator(1);
        check_if_negative();
        return *this;
    }
    Fraction& to_improper(){
        if (integer > 0){
            set_numerator(numerator + integer * denumenator);
            set_integer(0);
        }else if (integer < 0){
            set_numerator(integer * denumenator - numerator);
            set_integer(0);
        }
        return *this;
    }
    Fraction& reduce(){
        if (!numerator)
            return *this;
        int more, less, rest;
        if(numerator == denumenator){
            set_numerator(0);
            set_denumenator(1);
            integer++;
            return *this;
        }
        (numerator > denumenator)?(more = numerator, less = denumenator):(more = denumenator, less = numerator);
        for (rest = 1; rest; more = less, less = rest)
            rest = more%less;
        set_numerator(get_numerator()/more);
        set_denumenator(get_denumenator()/more);
        return *this;
    }
    void print_fraction()const{
        if (integer) {
            cout << integer;
            if (numerator){
                cout << "(" << numerator << "/" << denumenator << ")";
            }
            cout << endl;
            return;
        } else if (numerator){
            cout << numerator << "/" << denumenator << endl;
            return;
        }
        cout << 0 << endl;
    }
    //constructors/destructors:
    Fraction(){
        this->integer = 0;
        this->numerator = 0;
        this->denumenator = 1;
        cout << "0rd default Constructor" << endl;
    }
    Fraction(int integer){
        this->integer = integer;
        this->numerator = 0;
        this->denumenator = 1;
        cout << "1rd Constructor" << endl;
    }
    Fraction(int numerator, int denumenator){
        set_integer(0);
        set_numerator(numerator);
        set_denumenator(denumenator);
        check_if_negative();
        cout << "2rd Constructor" << endl;
    }
    Fraction(int integer, int numerator, int denumenator){
        set_integer(integer);
        set_numerator(numerator);
        set_denumenator(denumenator);
        check_if_negative();
        cout << "3rd Constructor" << endl;
    }
    Fraction(const Fraction& other){
        set_integer(other.get_integer());
        set_numerator(other.get_numerator());
        set_denumenator(other.get_denumenator());
        check_if_negative();
        cout << "Copy constructor" << endl;
    }
    ~Fraction(){
        cout << "Dectructor" << endl;
    }
    //operators:
    Fraction operator=(const Fraction& other){
        set_integer(other.get_integer());
        set_numerator(other.get_numerator());
        set_denumenator(other.get_denumenator());
        check_if_negative();
        return *this;
    }
    Fraction operator+=(Fraction other){
        this->to_improper();
        set_numerator(numerator * other.get_denumenator() + other.to_improper().get_numerator()*denumenator);
        set_denumenator(denumenator*other.get_denumenator());
        to_proper().reduce();
        return *this;
    }
    Fraction operator-=(Fraction other){
        this->to_improper();
        set_numerator(numerator * other.get_denumenator() - other.to_improper().get_numerator()*denumenator);
        set_denumenator(denumenator*other.get_denumenator());
        to_proper().reduce();
        return *this;
    }
    Fraction operator*=(Fraction other){
        this->to_improper();
        set_numerator(numerator * other.to_improper().get_numerator());
        set_denumenator(denumenator*other.get_denumenator());
        to_proper().reduce();
        return *this;
    }
    Fraction operator/=(Fraction other){
        this->to_improper();
        set_numerator(numerator * other.get_denumenator());
        set_denumenator(denumenator*other.to_improper().get_numerator());
        to_proper().reduce();
        return *this;
    }
    Fraction operator++(){
        return (*this += 1);
    }
    Fraction operator--(){
        return (*this -= 1);
    }
    Fraction operator++(int i){
        Fraction other = *this;
        *this += 1;
        return other;
    }
    Fraction operator--(int i){
        Fraction other = *this;
        *this -= 1;
        return other;
    }
};


#endif //HOMEWORKSOOP_FRACTION_H
