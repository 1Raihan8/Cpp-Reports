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

    void insertAtFirst(int a){
        node *newNode = new node(a);
        newNode -> next = head;
        head = newNode;
        return;
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
        current -> next = newNode;
    }

    void insertAtParticularPosition(int k, int a){
        if(k <= 0){
            cout << "Invalid Position" << endl;
            return;
        }

        node *newNode = new node(a);
        if(k == 1){
            newNode -> next = head;
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
            cout << "Invalid Position" << endl;
            delete newNode;
            return;
        }

        newNode -> next = position -> next;
        position -> next = newNode;
    }

    void deleteFirstPosition(){
        if(head == nullptr){
            cout << "The list is empty" << endl;
            return;
        }

        node *temp;
        temp = head;
        head = head -> next;
        delete temp;
        return;
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
    list.insertAtFirst(3);
    list.insertAtFirst(2);
    list.insertAtFirst(1);
    list.insertAtLast(4);
    list.insertAtLast(5);
    list.insertAtLast(6);
    list.insertAtParticularPosition(2, 5);
    list.deleteFirstPosition();

    list.print();
    return 0;
}