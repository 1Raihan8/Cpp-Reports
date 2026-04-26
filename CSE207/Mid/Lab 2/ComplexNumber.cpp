#include <bits/stdc++.h>
using namespace std;

class complexNumber{
    int real;
    int imaginary;

public:
    complexNumber(int a=0, int b=0){
        this -> real = a;
        this -> imaginary = b;
    }

    complexNumber add(complexNumber x){
        complexNumber y;
        y.real = this -> real + x.real;
        y.imaginary = this -> imaginary + x.imaginary;
        return y;
    }

    complexNumber sub(complexNumber x){
        complexNumber y;
        y.real = this -> real - x.real;
        y.imaginary = this -> imaginary - x.imaginary;
        return y;
    }

    void print(){
        if(this -> real == 0){
            cout << "";
        }
        else{
            cout << this -> real;
        }
    
        if(this -> imaginary == 0){
            cout << "";
        }
        else if(this -> imaginary > 0){
            cout << "+";
            cout << this -> imaginary << "i" << endl;
        }
        else{
            cout << this -> imaginary << "i" << endl;
        }
    }
};

int main(){
    complexNumber a = complexNumber(6, 7);
    complexNumber b = complexNumber(6, 6);
    complexNumber c;
    complexNumber d;

    c = a.add(b);
    d = b.sub(a);

    a.print();
    b.print();
    c.print();
    d.print();

    return 0;
}