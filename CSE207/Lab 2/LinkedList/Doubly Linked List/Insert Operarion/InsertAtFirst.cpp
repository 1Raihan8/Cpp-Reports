#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;
    node *previous;
    node(int a = 0){
        this -> data = a;
        this -> next = nullptr;
        this -> previous = nullptr;
    }
};

class DLL{
    node *head;
public:
    DLL(){
        this -> head = nullptr;
    }

    void insertAtFirst(int a){
        node *newNode = new node(a);
        if(head == nullptr){
            newNode -> next = head;
            head = newNode;
            return;
        }

        newNode -> next = head;
        head -> previous = newNode;
        head = newNode;
    }

    void print(){
        node *current = head;
        while(current != nullptr){
            cout << current -> data << " -> ";
            current = current -> next;
        }
        cout << "x" << endl;
    }
};

int main(){
    DLL list;
    list.insertAtFirst(3);
    list.insertAtFirst(2);
    list.insertAtFirst(1);

    list.print();
    return 0;
}