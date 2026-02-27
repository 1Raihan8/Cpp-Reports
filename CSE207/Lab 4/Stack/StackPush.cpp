#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;
    node(int a = 0){
        this -> data = a;
        this -> next = nullptr;
    }
};

class Stack{
    node *top;
    int length, maxSize;
public:
    Stack(){
        this -> top = nullptr;
        length = 0;
        maxSize = 10000;
    }

    bool isFull(){
        if(length == maxSize){
            return true;
        }
        else{
            return false;
        }
    }

    bool isEmpty(){
        if(length == 0){
            return true;
        }
        else{
            return false;
        }
    }

    int getTop(){
        if(isEmpty()){
            throw runtime_error("Stack is empty");
        }
        return top -> data;
    }

    int getLength(){
        return length;
    }

    void push(int a){
        if(isFull()){
            throw runtime_error("Stack overflows!!!");
        }

        node *newNode = new node(a);
        newNode -> next = top;
        top = newNode;
        length = length + 1;
    }

    void print(){
        node *current = top;
        while(current != nullptr){
            cout << current -> data << " -> ";
            current = current -> next;
        }
        cout << "x" << endl;
    }
};

int main(){
    Stack stk;
    stk.push(3);
    stk.push(2);
    stk.push(1);

    cout << "Length: " << stk.getLength() << " Top: " << stk.getTop() << endl;
    stk.print();
    return 0; 
}