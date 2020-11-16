#include <iostream>
using  namespace std;
class Fraction{
    int integer;
    int numerator;
    int denomenator;
public:
    int get_integer()const{
        return this->integer;
    }
    int get_numerator()const{
        return this->numerator;
    }
    int get_denominator()const{
        return this->denomenator;
    }
    void set_integer(int integer){
        this->integer = integer;
    }
    void set_numenator(int numenator){
        this->numerator = numenator;
    }
    void set_denomenator(int denomenator){
        this->denomenator = denomenator ? denomenator : 1;
    }
    //methods:
    void print_fraction()const{
        //cout << this->integer << " " << this->numerator << "/" << this->denomenator << endl;
        if (integer)cout << integer;
        if (numerator){
            if(integer)cout << "(";
            cout << numerator << "/" << denomenator;
            if(integer)cout << ")";
        }
        if(integer == 0 && numerator == 0)cout << 0;
        cout << endl;
    }
    void print_fraction_m()const{
        //cout << this->integer << " " << this->numerator << "/" << this->denomenator << endl;
        if (integer)cout << integer;
        if (numerator){
            if(integer)cout << "(";
            cout << numerator << "/" << denomenator;
            if(integer)cout << ")";
        }
        if(integer == 0 && numerator == 0)cout << 0;
        cout << "\t";
    }
    void print_adress()const{
        cout << "Object:\t\t" << this << endl;
        cout << "Integer:\t\t" << &integer << endl;
        cout << "Numenator:\t\t" << &numerator << endl;
        cout << "Denomerator:\t" << &denomenator << endl;
    }
    void to_proper(){
        if (this->numerator < this->denomenator){
            cout << "Nothing to do!" << endl;
            return;
        }
        integer += numerator / denomenator;
        numerator = numerator%denomenator;
        cout << "The fraction was reduced." << endl;
        if (!numerator){
            cout << "Completelly!" << endl;
            denomenator = 1;
        }
    }
    void to_improper(){
        if(!this->integer || !this->numerator || this->denomenator==1){
            cout << "Nothing to do!" << endl;
            return;
        }
        numerator = numerator + denomenator * integer;
        integer = 0;
        cout << "Fraction now improper!" << endl;
    }
    void reduce(){
        bool is_changed = false;
        for(int i = denomenator; i > 1; i--){
            if(denomenator%i == 0 && numerator%i == 0){
                numerator /= i;
                denomenator /= i;
                is_changed = true;
            }
        }
        if (denomenator == 1){
            integer = numerator;
            numerator = 0;
        }
        if (is_changed){
            cout << "The fraction was reduced!" << endl;
        }
    }
    //Constructors
    Fraction(){
        this->integer = this->numerator = 0;
        this->denomenator = 1;
        //cout << "Default Constructor:\t" << this << endl;
    }
    Fraction(int integer){
        this->integer = integer;
        this->numerator = 0;
        this->denomenator = 1;
        //cout << "1 arg. Constructor:\t" << this << endl;
    }
    Fraction(int numerator, int denumerator){
        this->integer = 0;
        this->numerator = numerator;
        this->denomenator = denumerator;
        //cout << "2 arg. Constructor:\t" << this << endl;
    }
    Fraction(int integer , int numerator, int denumerator){
        this->set_integer(integer);
        this->set_numenator(numerator);
        this->set_denomenator(denumerator);
        //cout << "3 arg. Constructor:\t" << this << endl;
    }
    Fraction(const Fraction& other){
        this->integer = other.integer;
        this->numerator = other.numerator;
        this->denomenator = other.denomenator;
        cout << "CopyConstructor:\t" << this << endl;
    }
    ~Fraction(){
        //cout << "Destrictor:\t" << this << endl;
    }
    //Operators:
    Fraction& operator=(const Fraction& other){
        this->integer = other.integer;
        this->numerator = other.numerator;
        this->denomenator = other.denomenator;
        cout << "CopyAssignment:\t" << this << endl;
        return *this;
    }
};
Fraction operator+(Fraction one, Fraction two){
    Fraction resultFr;
    one.to_proper();
    two.to_proper();
    resultFr.set_integer(one.get_integer()+two.get_integer());
    if (one.get_denominator() == two.get_denominator()){
        resultFr.set_numenator(one.get_numerator()+two.get_numerator());
        resultFr.set_denomenator(one.get_denominator());
        resultFr.reduce();
    }else{
        resultFr.set_numenator(one.get_numerator()*two.get_denominator()+two.get_numerator()*one.get_denominator());
        resultFr.set_denomenator(one.get_denominator()*two.get_denominator());
        resultFr.reduce();
    }
    one.print_fraction_m();cout << " + ";two.print_fraction_m();cout << " = ";resultFr.print_fraction();
    return resultFr;
}
//#define CONSRUCTORS_CHECK
int main() {
    setlocale(LC_ALL,"Russian");
#ifdef CONSRUCTORS_CHECK
    Fraction myfract00;
    myfract00.print_fraction();
    myfract00.print_adress();
    Fraction myfract01(2);
    myfract01.print_fraction();
    myfract01.print_adress();
    Fraction myfract02(2,3);
    myfract02.print_fraction();
    myfract02.print_adress();
    Fraction myfract03(2,3,4);
    myfract03.print_fraction();
    myfract03.print_adress();
    cout << sizeof(Fraction) << endl;
#endif
    Fraction myFraction01(2,1,2);
    myFraction01.print_fraction();
    myFraction01.to_proper();
    myFraction01.print_fraction();
    myFraction01.to_improper();
    myFraction01.print_fraction();
    cout << "++++++++++++++++++++++++++++++++++++++++" << endl;
    Fraction myFraction02(2,4,2);
    myFraction02.print_fraction();
    myFraction02.to_proper();
    myFraction02.print_fraction();
    myFraction02.to_improper();
    myFraction02.print_fraction();
    cout << "++++++++++++++++++++++++++++++++++++++++" << endl;
    Fraction myFraction03(2,9,2);
    myFraction03.print_fraction();
    myFraction03.to_proper();
    myFraction03.print_fraction();
    myFraction03.to_improper();
    myFraction03.print_fraction();
    cout << "++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Trying to reduce fraction:" << endl;
    Fraction myFraction04(12,36);
    myFraction04.print_fraction();
    myFraction04.reduce();
    myFraction04.print_fraction();
    cout << "Trying to summ fraction:" << endl;
    Fraction myFraction05;
    myFraction05 = myFraction01 + myFraction04;
    return 0;
}