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

    ~linkedList(){
        node *current = head;
        node *temp;
        while(current != nullptr){
            temp = current;
            current = current -> next;
            delete temp;
        }
        head = nullptr;
        cout << "LinkedList deleted successfully" << endl;
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
    linkedList list;
    list.insertAtLast(1);
    list.insertAtLast(2);
    list.insertAtLast(3);
    list.insertAtLast(4);

    list.print();
    return 0;
}