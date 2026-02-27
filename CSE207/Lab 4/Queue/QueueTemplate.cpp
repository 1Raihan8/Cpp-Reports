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

template <typename Type> class Queue{
    node<Type> *front;
    node<Type> *rear;
    int length, maxSize;
public:
    Queue(){
        this -> front = nullptr;
        this -> rear = nullptr;
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

    Type getFront(){
        if(isEmpty()){
            throw runtime_error("Queue is Empty");
        }
        return front -> data;
    }

    int getLength(){
        return length;
    }

    void enqueue(Type a){
        if(isFull()){
            throw runtime_error("Queue overflows!!!");
        }
        
        node<Type> *newNode = new node<Type>(a);
        if(front == nullptr){
            newNode -> next = front;
            front = newNode;
            rear = newNode;
        }
        else{
            rear -> next = newNode;
            rear = newNode;
        }

        length = length + 1;
    }

    void dequeue(){
        if(isEmpty()){
            throw runtime_error("Queue underflows!!!");
        }

        node<Type> *temp;
        temp = front;
        front = front -> next;
        delete temp;
        length = length - 1;
    }

    ~Queue(){
        while(!isEmpty()){
            dequeue();
        }
    }

    void print(){
        node<Type> *current = front;
        while(current != nullptr){
            cout << current -> data << " -> ";
            current = current -> next;
        }
        cout << "x" << endl;
    }
};

int main(){
    Queue<int> que;

    que.enqueue(1);
    que.enqueue(2);
    que.enqueue(3);

    cout << "Length: " << que.getLength() << " Front: " << que.getFront() << endl;
    que.print();
    return 0;
}