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

    void insertAtFirst(node a){
        node *newNode = new node(a);
        newNode -> next = head;
        head = newNode; 
    }

    void insertAtLast(node a){
        node *newNode = new node(a);
        if(head == nullptr){
            newNode -> next = head;
            head = newNode;
        }

        node *current = head;
        while(current -> next != nullptr){
            current = current -> next;
        }
        current -> next = newNode;
    }

    void print(){
        node *current = head;
        cout << "The List: ";
        while(current != nullptr){
            cout << current -> data << " -> ";
            current = current -> next;
        }
        cout << "x" << endl;
    }

    void count(){
        if(head == nullptr){
            cout << "The list is empty";
            return;
        }
        int count = 0;
        node *current = head;
        while(current != nullptr){
            count = count + 1;
            current = current -> next;
        }
        cout << "Count is: " << count << endl;
    }
};

int main(){
    linkedList list;
    list.insertAtFirst(1);
    list.insertAtFirst(0);
    list.insertAtLast(2);

    list.print();
    list.count();
    return 0;
}