#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;
    node(int a){
        this -> data = a;
        this -> next = nullptr;
    }
};

class Queue{
    node *front;
    node *rear;
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

    int getFront(){
        if(isEmpty()){
            throw runtime_error("Queue is Empty");
        }
        return front -> data;
    }

    int getLength(){
        return length;
    }

    void enqueue(int a){
        if(isFull()){
            throw runtime_error("Queue overflows!!!");
        }
        
        node *newNode = new node(a);
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

        node *temp;
        temp = front;
        front = front -> next;
        delete temp;
        if(length = 1){
            rear =  nullptr;
        }
        length = length - 1;
    }

    ~Queue(){
        while(!isEmpty()){
            dequeue();
        }
    }

    void print(){
        node *current = front;
        while(current != nullptr){
            cout << current -> data << " -> ";
            current = current -> next;
        }
        cout << "x" << endl;
    }
};

int main(){
    Queue que;
    que.enqueue(1);
    que.enqueue(2);
    que.enqueue(3);
    que.dequeue();

    cout << "Length: " << que.getLength() << " Front: " << que.getFront() << endl;
    que.print();
    return 0;
}