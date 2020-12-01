#include <iostream>
#include "Fraction.h"
#define line "---------------\n"
#define int_input 20
using namespace std;
using std::ostream;
using std::istream;
inline Fraction operator+(Fraction one, Fraction two);
inline Fraction operator-(Fraction one, Fraction two);
inline Fraction operator*(Fraction one, Fraction two);
inline Fraction operator/(Fraction one, Fraction two);
ostream& operator<<(ostream& os, Fraction& fract);
istream& operator>>(istream& os, Fraction& fract);
bool operator<(Fraction one, Fraction two);
bool operator<=(Fraction one, Fraction two);
bool operator>(Fraction one, Fraction two);
bool operator>=(Fraction one, Fraction two);
void casting_fractions(Fraction& one, Fraction& two);
int check_int_input();
int char_input(char arr[], bool& succes);

int main() {
    setlocale(LC_ALL, "");
    cout << line;
    Fraction One(2, 4, -8);
    cout << One << " reduced: " << One.reduce() << " improper: " << One.to_improper() << "Proper: " << One.to_proper() << endl;
    cout << line;
    Fraction Two = One;
    cout << One << " = " << Two << endl;
    cout << line;
    cout << "Сложение:" << endl;
    Fraction Three = Two + One;
    cout << Two << " + " << Two << " = " << Three << endl;
    cout << line;
    cout << "Вычиание:" << endl;
    Three.set_denumenator(5);
    Three.set_numerator(3);
    Fraction Four = Two - Three;
    cout << Two << " - " << Three << " = " << Four << endl;
    cout << line;
    cout << "Умножение:" << endl;
    Fraction Five = One * Two;
    cout << One << " * " << Two  << " = " << Five << endl;
    cout << line;
    cout << "Деление:" << endl;
    Five = One / Two;
    cout << One << " / " << Two << " = " << Five << endl;
    cout << line;
    cout << Five << " += " << One << endl;
    Five += One;
    cout <<  Five << endl;
    cout << line;
    cout << Five << " -= " << One << endl;
    Five -= One;
    cout << Five << endl;
    cout << line;
    cout << Three << " *= " << One << endl;
    Three *= One;
    cout << Three << endl;
    cout << line;
    cout << Five << " /= " << One << endl;
    Five /= One;
    cout << Five << endl;
    cout << line;
    cout << Five << "--" << endl;
    Five--;
    cout << Five << endl;
    cout << line;
    cout << "Сравнение: " << endl;
    cout << Three << " <= " << Three << "результат :" << (Three <= Three) << endl;
    cout << line;
    Fraction InputFract;
    cin >> InputFract;
    cout << "Введенная дробь: " << InputFract << endl;
    return 0;
}
inline Fraction operator+(Fraction one, Fraction two){
    Fraction result(one.to_improper().get_numerator()*two.get_denumenator()+
        one.get_denumenator()*two.to_improper().get_numerator(),one.get_denumenator()*two.get_denumenator());
    return result.reduce().to_proper();
}
inline Fraction operator-(Fraction one, Fraction two){
    Fraction result(one.to_improper().get_numerator()*two.get_denumenator()-
                    one.get_denumenator()*two.to_improper().get_numerator(),one.get_denumenator()*two.get_denumenator());
    return result.reduce().to_proper();
}
inline Fraction operator*(Fraction one, Fraction two){
    Fraction result(one.to_improper().get_numerator()*two.to_improper().get_numerator(),
                    one.get_denumenator()*two.get_denumenator());
    return result.to_proper().reduce();
}
inline Fraction operator/(Fraction one, Fraction two){
    Fraction result(one.to_improper().get_numerator()*two.get_denumenator(),
                    two.to_improper().get_numerator()*one.get_denumenator());
    return result.reduce().to_proper();
}
ostream& operator<<(ostream& os, Fraction& fract){
    if (fract.get_integer()) {
        cout << fract.get_integer();
        if (fract.get_numerator()){
            cout << "(" << fract.get_numerator() << "/" << fract.get_denumenator() << ")";
        }
        return os;
    } else if (fract.get_numerator()){
        cout << fract.get_numerator() << "/" << fract.get_denumenator();
        return os;
    }
    cout << 0;
    return os;
}
istream& operator>>(istream& in, Fraction& fract){
    cout << "Введите целую часть: ";
    int i_input = check_int_input();
    fract.set_integer(i_input);
    cout << "Введите числитель: ";
    i_input = check_int_input();
    fract.set_numerator(i_input);
    cout << "Введите знаменатель: ";
    i_input = check_int_input();
    fract.set_denumenator(i_input);
    return in;
}
bool operator<(Fraction one, Fraction two){
    casting_fractions(one, two);
    return (one.get_numerator() < two.get_numerator())?true: false;
}
bool operator<=(Fraction one, Fraction two){
    casting_fractions(one, two);
    return (one.get_numerator() <= two.get_numerator())?true: false;
}
bool operator>(Fraction one, Fraction two){
    casting_fractions(one, two);
    return (one.get_numerator() > two.get_numerator())?true: false;
}
bool operator>=(Fraction one, Fraction two){
    casting_fractions(one, two);
    return (one.get_numerator() >= two.get_numerator())?true: false;
}
void casting_fractions(Fraction& one, Fraction& two){
    one.to_improper().set_numerator(one.get_numerator()*two.get_denumenator());
    two.to_improper().set_numerator(two.get_numerator()*one.get_denumenator());
    one.set_denumenator(one.get_denumenator()*two.get_denumenator());
    two.set_denumenator(one.get_denumenator());
}
int char_input(char arr[], bool& succes){
    int result = 0;
    int len = 0;
    for (int i = 0; i < int_input; i++){
        if(arr[i]){
            len++;
        }else{
            break;
        }
    }
    int multiplier = 1;
    for (int i = len-1; i > 0; i--) {
        if (arr[i] > 47 && arr[i] < 58) {
            result += ((int(arr[i]) - 48) * multiplier);
            multiplier *= 10;
        } else {
            cout << "Введено некорректное значение!" << endl;
            succes = false;
            return 0;
        }
    }
        if (arr[0] == 45){
            result *= -1;
        }else{
            if (arr[0] > 47 && arr[0] < 58){
                result += ((int(arr[0])-48)*multiplier);
            }else{
                cout << "Введено некорректное значение!" << endl;
                succes = false;
                return 0;
            }
        }
        succes = true;
        return result;
}
int check_int_input(){
    bool succes = false;
    char input[int_input]{};
    int result;
    do {
        cin.getline(input,int_input);
        result = char_input(input, succes);
    }while(!succes);
    return result;
}