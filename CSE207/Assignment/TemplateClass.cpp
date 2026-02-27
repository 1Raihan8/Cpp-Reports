#include <bits/stdc++.h>
using namespace std;

template <typename T> class Node{
public:
    T data;
    Node<T> *next;

    // Constructor
    Node(T a){
        this -> data = a;
        this -> next = nullptr;
    }
};

template <typename T> class LinkedList{
    Node<T> *head;
    
public:
    // Constructor
    LinkedList(){
        this -> head = nullptr;
    }

    void insertAtParticularPosition(int k, T value){
        if(k <= 0){
            cout << "Invalid Position" << endl;
            return;
        }

        Node<T> *newNode = new Node<T>(value);
        if(k == 1){
            newNode -> next = head;
            head = newNode;
            return;
        }

        int count = 1;
        Node<T> *position = head;
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

        Node<T> *temp;
        if(value == head -> data){
            temp = head;
            head = head -> next;
            delete temp;
            return;
        }

        Node<T> *current = head;
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
        Node<T> *current = head;
        while(current != nullptr){
            cout << current -> data << " -> ";
            current = current -> next;
        }
        cout << "x" << endl;
    }

    ~LinkedList() {
        Node<T> *current = head;
        Node<T> *temp;
        while (current != nullptr) {
            temp = current;
            current = current -> next;
            delete temp;
        }
        head = nullptr;
    }
};

int main() {
    LinkedList<int> list;

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