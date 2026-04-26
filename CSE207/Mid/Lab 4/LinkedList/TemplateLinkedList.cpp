#include <bits/stdc++.h>
using namespace std;

template <typename Type> class node{
public:
    Type data;
    node<Type> *next;
    node(Type a){
        this -> data = a;
        this -> next = nullptr;
    }
};

template <typename Type> class linkedList{
    node<Type> *head;
public:
    linkedList(){
        this -> head = nullptr;
    }

    void insertAtFirst(Type a){
        node<Type> *newNode = new node<Type>(a);
        newNode -> next = head;
        head = newNode;
    }

    void insertAtParticularPosition(int k, Type a){
        if(k <= 0){
            cout << "Invalid position" << endl;
            return;
        }

        node<Type> *newNode = new node<Type>(a);
        if(k == 1){
            newNode -> next = head;
            head = newNode;
            return;
        }

        int count = 1;
        node<Type> *current = head;
        while(current != nullptr && count < k-1){
            current = current -> next;
            count = count + 1;
        }

        if(current == nullptr){
            cout << "Invalid position" << endl;
            delete newNode;
            return;
        }

        newNode -> next = current -> next;
        current -> next = newNode;
    }

    void deleteFirstPosition(){
        if(head == nullptr){
            cout << "The list is empty" << endl;
            return;
        }

        node<Type> *temp;
        temp = head;
        head = head -> next;
        delete temp;
    }

    void deleteParticularPosition(int k){
        if(head == nullptr){
            cout << "The list is empty" << endl;
            return;
        }

        node<Type> *temp;
        if(k == 1){
            temp = head;
            head = head -> next;
            delete temp;
            return;
        }
        
        int count = 1;
        node<Type> *current = head;
        while(current != nullptr && count < k-1){
            current = current -> next;
            count = count + 1;
        }

        if(current == nullptr){
            cout << "Invalid position" << endl;
            return;
        }

        temp = current -> next;
        current -> next = temp -> next;
        delete temp;
    }

    void print(){
        node<Type> *current = head;
        while(current != nullptr){
            cout << current -> data << " -> ";
            current = current -> next;
        }
        cout << "x" << endl;
    }
};

int main(){
    linkedList<int> list1;
    list1.insertAtFirst(3);
    list1.insertAtFirst(2);
    list1.insertAtFirst(1);
    list1.insertAtParticularPosition(2, 5);

    linkedList<char> list2;
    list2.insertAtFirst('c');
    list2.insertAtFirst('b');
    list2.insertAtFirst('a');

    list1.print();
    list2.print();
    return 0;
}