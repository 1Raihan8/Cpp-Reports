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

class linkedList{
    node *head;
public:
    linkedList(){
        this -> head = nullptr;
    }

    void insertAscendingOrder(int value){
        node *newNode = new node(value);

        if(head == nullptr || value < head -> data){
            newNode -> next = head;
            head = newNode;
            return;
        }

        node *current = head;
        while(current -> next != nullptr && current -> next -> data < value){
            current = current -> next;
        }
        newNode -> next = current -> next;
        current -> next = newNode;
    }

    void print(){
        node *current = head;
        while(current != nullptr){
            cout << current -> data << " -> ";
            current = current -> next;
        }
        cout << "x";
    }
};

int main(){
    linkedList list;
    list.insertAscendingOrder(10);
    list.insertAscendingOrder(20);
    list.insertAscendingOrder(5);
    list.insertAscendingOrder(45);
    list.insertAscendingOrder(31);
    list.insertAscendingOrder(37);

    list.print();
    return 0;
}