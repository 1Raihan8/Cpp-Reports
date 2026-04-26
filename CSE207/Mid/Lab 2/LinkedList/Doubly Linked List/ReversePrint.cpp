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

    void insertAtLast(int a){
        node *newNode = new node(a);
        if(head == nullptr){
            newNode -> next = head;
            head = head;
            return;
        }

        node *current = head;
        while(current -> next != nullptr){
            current = current -> next;
        }
        newNode -> next = current -> next;
        current -> next = newNode;
        newNode -> previous = current;
    }

    void insertAtParticularPosition(int k, int a){
        if(k <= 0){
            cout << "Invalid position" << endl;
            return;
        }
        
        node *newNode = new node(a);
        if(k == 1){
            if(head == nullptr){
                newNode -> next = head;
                head = newNode;
                return;
            }
            newNode -> next = head;
            head -> previous = newNode;
            head = newNode;
            return;
        }

        int count = 1;
        node *current = head;
        while(current != nullptr && count < k-1){
            current = current -> next;
            count = count + 1;
        }
        newNode -> next = current -> next;
        if(current -> next != nullptr){
            current -> next -> previous = newNode;
        }
        current -> next = newNode;
        newNode -> previous = current;
    }

    void print(){
        node *current = head;
        while(current != nullptr){
            cout << current -> data << " -> ";
            current = current -> next;
        }
        cout << "x" << endl;
    }

    void reversePrint(){
        node *current = head;
        while(current -> next != nullptr){
            current = current -> next;
        }

        while(current != nullptr){
            cout << current -> data << " -> ";
            current = current -> previous;
        }
        cout << "x" << endl;
    }
};

int main(){
    DLL list;
    list.insertAtFirst(3);
    list.insertAtFirst(2);
    list.insertAtFirst(1);
    list.insertAtLast(4);
    list.insertAtLast(6);
    list.insertAtLast(7);
    list.insertAtParticularPosition(5, 5);

    list.print();
    list.reversePrint();
    return 0;    
}