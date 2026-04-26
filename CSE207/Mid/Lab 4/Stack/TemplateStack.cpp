#include <bits/stdc++.h>
using namespace std;

template <typename Type> class node{
public:
    Type data;
    node<Type> *next;
    node(Type a){
        this -> data = a;
        this -> next = nullptr;
    }
};

template <typename Type> class Stack{
    node<Type> *top;
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

    Type getTop(){
        if(isEmpty()){
            throw runtime_error("Stack is empty");
        }

        return top -> data;
    }

    int getLength(){
        return length;
    }

    void push(Type a){
        if(isFull()){
            throw runtime_error("Stack is full");
        }

        node<Type> *newNode = new node<Type>(a);
        newNode -> next = top;
        top = newNode;
        length = length + 1;
    }

    void pop(){
        if(isEmpty()){
            throw runtime_error("Stack is empty");
        }

        node<Type> *temp;
        temp = top;
        top = top -> next;
        delete temp;
        length = length - 1;
    }

    ~Stack(){
        while(!isEmpty()){
            pop();
        }
    }

    void print(){
        node<Type> *current = top;
        while(current != nullptr){
            cout << current -> data << " -> ";
            current = current -> next;
        }
        cout << "x" << endl;
    }
};

int main(){
    Stack<char> stk;
    stk.push('a');
    stk.push('b');
    stk.push('c');
    stk.pop();

    cout << "Length: " << stk.getLength() << " Top: " << stk.getTop() << endl;;
    stk.print();
    return 0;
}