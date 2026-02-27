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

    void insertAtFirst(int a){
        node *newNode = new node(a);
        newNode -> next = head;
        head = newNode;
    }

    // For printing that it has successfully inserted at first
    void print(){
        node *current;
        current = head;
        while(current != nullptr){
            cout << current -> data << " -> ";
            current = current -> next;
        }
        cout << "x";
    }
};

int main(){
    linkedList list;
    list.insertAtFirst(1);
    list.insertAtFirst(2);
    list.insertAtFirst(3);
    list.insertAtFirst(4);
    list.insertAtFirst(5);

    list.print();
    return 0;
}
