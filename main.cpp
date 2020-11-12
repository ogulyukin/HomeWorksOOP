#include <iostream>
#include "math.h"
#include "string.h"
using namespace std;
class Fraction{
    int Numerator;
    int Denumerator;
public:
    int get_Numerator(){
        return this->Numerator;
    }
    int get_Denumerator(){
        return this->Denumerator;
    }
    void set_fraction(int Numerator, int Denumerator){
        this->Numerator = Numerator;
        this->Denumerator = Denumerator;
    }
    void show_fraction(){
        cout << this->Numerator << "/" << this->Denumerator << endl;
    }

    //Consturctors
    Fraction(int Numerator = 0, int Denumerator = 1){
        this->Numerator = Numerator;
        this->Denumerator = Denumerator;
    }
    Fraction(double fraction){
        int count = 1;
        int temp1 = int(fraction);
        double temp2 = fraction;
        while((temp2-temp1) != 0 && (temp2-temp1 != 1)){
            count *= 10;
            temp2 *= 10;
            temp1 = int(temp2);
        }
        this->Numerator = temp2;
        this->Denumerator = count;
    }
    ~Fraction(){
    }
};
int main() {
    Fraction fraction(123.453);
    fraction.show_fraction();
    Fraction fract(4,34);
    fract.show_fraction();
    return 0;
}
