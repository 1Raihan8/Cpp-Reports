#include <bits/stdc++.h>
using namespace std;

template <typename T> class node{
public:
    T data;
    node<T> *next;

    // Constructor
    node(T a){
        this -> data = a;
        this -> next = nullptr;
    }
};

template <typename T> class linkedList{
    node<T> *head;
    
public:
    // Constructor
    linkedList(){
        this -> head = nullptr;
    }

    void insertAtParticularPosition(int k, T value){
        if(k <= 0){
            cout << "Invalid Position" << endl;
            return;
        }

        node<T> *newNode = new node<T>(value);
        if(k == 1){
            newNode -> next = head;
            head = newNode;
            return;
        }

        int count = 1;
        node<T> *position = head;
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

    void deleteParticularValue(T value){
        if(head == nullptr){
            cout << "The list is empty" << endl;
            return;
        }

        node<T> *temp;
        if(value == head -> data){
            temp = head;
            head = head -> next;
            delete temp;
            return;
        }

        node<T> *current = head;
        while(current -> next != nullptr && current -> next -> data != value){
            current = current -> next;
        }
        
        if(current -> next == nullptr){
            cout << "Element not found" << endl;
            return;
        }

        temp = current -> next;
        current -> next = current -> next -> next;
        delete temp;
    }

    void print(){
        node<T> *current = head;
        while(current != nullptr){
            cout << current -> data << " -> ";
            current = current -> next;
        }
        cout << "x" << endl;
    }

    ~linkedList() {
        node<T> *current = head;
        node<T> *temp;
        while (current != nullptr) {
            temp = current;
            current = current -> next;
            delete temp;
        }
        head = nullptr;
    }
};

int main() {
    linkedList<int> list;

    list.insertAtParticularPosition(1, 10);
    list.insertAtParticularPosition(2, 20);
    list.insertAtParticularPosition(3, 30);
    list.insertAtParticularPosition(2, 15);

    cout << "Linked List: ";
    list.print();

    list.deleteParticularValue(20);
    cout << "After deleting: ";
    list.print();
    return 0;
}