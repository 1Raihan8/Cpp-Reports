#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;
    node(int a=0){
        this -> data = a;
        this -> next = nullptr;
    }
};

class linkedList{
    node *head;
public:
    linkedList(){
        this -> head = nullptr;
    }

    void insertAtLast(int a){
        node *newNode = new node(a);
        if(head == nullptr){
            newNode -> next = nullptr;
            head = newNode;
            return;
        }
        node *position;
        position = head;
        while(position -> next != nullptr){
            position = position -> next;
        }
        newNode -> next = position -> next;
        position -> next = newNode;
    }

    void mergeLinkedList(linkedList X){
        if(head == nullptr){
            this -> head = X.head;
            return;
        }

        node *current = head;
        while(current -> next != nullptr){
            current = current -> next;
        }
        current -> next = X.head;
    }

    // For printing that it has successfully inserted at first
    void print(){
        node *current;
        current = head;
        while(current != nullptr){
            cout << current -> data << " -> ";
            current = current -> next;
        }
        cout << "x" << endl;
    }
};

int main(){
    linkedList a;
    linkedList b;
    a.insertAtLast(1);
    a.insertAtLast(2);
    a.insertAtLast(3);
    a.insertAtLast(4);

    b.insertAtLast(1);
    b.insertAtLast(2);
    b.insertAtLast(3);

    a.print();
    b.print();
    a.mergeLinkedList(b);

    a.print();
    return 0;
}