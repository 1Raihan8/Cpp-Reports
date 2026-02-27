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

class CircularLinkedList{
    node *head;
    node *tail;
public:
    CircularLinkedList(){
        this -> head = nullptr;
        this -> tail = nullptr;
    }

    void insertAtFirst(int a){
        node *newNode = new node(a);
        if(head == nullptr){
            newNode -> next = head;
            head = tail = newNode;
            tail -> next = head;

        }
        newNode -> next = head;
        head = newNode;
        tail -> next = head;
    }

    void insertAtLast(int a){
        node *newNode = new node(a);
        if(head == nullptr){
            newNode -> next = nullptr;
            head = tail = newNode;
            tail -> next = head;
            return;
        }
        else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    // For printing that it has successfully inserted at first
    void print() {
        if (head == nullptr){
            cout << "The list is empty" << endl;
            return;
        }

        node *current = head;
        do {
            cout << current -> data << " -> ";
            current = current->next;
        } while (current != head);

        cout << "(back to head)";
    }
};

int main(){
    CircularLinkedList list;
    list.insertAtFirst(1);
    list.insertAtFirst(2);
    list.insertAtFirst(3);
    list.insertAtFirst(4);
    list.insertAtFirst(5);

    list.insertAtLast(6);
    list.insertAtLast(7);
    list.insertAtLast(8);

    list.print();
    return 0;
}
