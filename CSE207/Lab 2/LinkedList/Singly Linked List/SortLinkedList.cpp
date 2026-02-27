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

    void isSorted(){
        if(head == nullptr || head -> next == nullptr){
            cout << "The list is sorted" << endl;
            return;
        }

        node *current = head;
        bool asc = true, des = true;
        while(current -> next != nullptr){
            if (current -> data > current -> next -> data){
                asc = false;
            }
            if (current -> data < current -> next -> data){
                des = false;
            }

            current = current->next;
        }

        if (asc || des){
            cout << "The list is sorted" << endl;
        }
        else{
            cout << "The list is not sorted" << endl;
        }
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
    list.isSorted();
    return 0;
}