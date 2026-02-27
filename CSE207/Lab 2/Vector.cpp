#include <bits/stdc++.h>
using namespace std;

class vectorDemo{
    int first;
    int second;
    int third;

public: 
    vectorDemo(int a=0, int b=0, int c=0){
        this -> first = a;
        this -> second = b;
        this -> third = c;
    }

    vectorDemo add(vectorDemo r){
        vectorDemo p;
        p.first = this -> first + r.first;
        p.second = this -> second + r.second;
        p.third = this -> third + r.third;
        return p;
    }

    vectorDemo sub(vectorDemo r){
        vectorDemo p;
        p.first = this -> first - r.first;
        p.second = this -> second - r.second;
        p.third = this -> third - r.third;
        return p;
    }

    void print(){
        if(this -> first == 0){
            cout << "";
        }
        else{
            cout << this -> first << "i";
        }

        if(this -> second == 0){
            cout << "";
        }
        else if(this -> second > 0){
            cout << "+";
            cout << this -> second << "j";
        }
        else{
            cout << this -> second << "j";
        }

        if(this -> third == 0){
            cout << "";
        }
        else if(this -> third > 0){
            cout << "+";
            cout << this -> third << "k" << endl;
        }
        else{
            cout << this -> third << "k" << endl;
        }
    }
};

int main(){
    vectorDemo a = vectorDemo(1, 2, 3);
    vectorDemo b = vectorDemo(1, 3, 3);
    vectorDemo c;
    vectorDemo d;

    c = a.add(b);
    d = a.sub(b);

    a.print();
    b.print();
    c.print();
    d.print();

    return 0;
}