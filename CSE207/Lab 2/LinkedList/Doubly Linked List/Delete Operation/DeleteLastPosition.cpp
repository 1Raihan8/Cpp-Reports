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
            head = newNode;
            return;
        }

        node *current = head;
        while(current -> next != nullptr){
            current = current -> next;
        }

        newNode -> next = current -> next;
        newNode -> previous = current;
        current -> next = newNode;
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
        node *position = head;
        while(count < k-1 && position != nullptr){
            position = position -> next;
            count = count + 1;
        }

        if(position == nullptr){
            cout << "Invalid position" << endl;
            return;
        }
        newNode -> next = position -> next;
        newNode -> previous = position;
        position -> next = newNode;
    } 

    void deleteFirstPosition(){
        if(head == nullptr){
            cout << "The list is empty" << endl;
            return;
        }
        
        node *temp = head;
        head = head -> next;
        if(head != nullptr){
            head -> previous = nullptr;
        }
        delete temp;
    }

    void deleteLastPosition(){
        if(head == nullptr){
            cout << "The list is empty" << endl;
            return;
        }

        node *temp;
        if(head -> next == nullptr){
            temp = head;
            head = head -> next;
            delete temp;
            return;
        }

        node *current = head;
        while(current -> next -> next != nullptr){
            current = current -> next;
        }
        temp = current -> next;
        current -> next = nullptr;
        delete temp;
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
    DLL list;
    list.insertAtFirst(3);
    list.insertAtFirst(2);
    list.insertAtFirst(1);
    list.insertAtLast(4);
    list.insertAtLast(5);
    list.insertAtLast(6);
    list.insertAtParticularPosition(2, 5);
    list.deleteFirstPosition();
    list.deleteLastPosition();

    list.print();
    return 0;
}