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

    node *getHead(){
        return head;
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

    void print(){
        node *current = head;
        while(current != nullptr){
            cout << current -> data << " -> ";
            current = current -> next;
        }
        cout << "x" << endl;
    }

    node* mergeTwoSortedLists(node *list1, node *list2){
        vector<int> v;
        node *current1 = list1;
        while(current1 != nullptr){
            v.push_back(current1 -> data);
            current1 = current1 -> next;
        }

        node *current2 = list2;
        while(current2 != nullptr){
            v.push_back(current2 -> data);
            current2 = current2 -> next;
        }

        sort(v.begin(), v.end());

        node *newNode = new node(0);
        node *current = newNode;

        for(int x : v){
            current -> next = new node(x);
            current = current -> next;
        }

        return newNode -> next;
    }
};

int main(){
    linkedList list1;
    list1.insertAtLast(1);
    list1.insertAtLast(2);
    list1.insertAtLast(4);
    
    linkedList list2;
    list2.insertAtLast(1);
    list2.insertAtLast(3);
    list2.insertAtLast(4);

    list1.print();
    list2.print();

    linkedList list;
    node *mergedHead = list.mergeTwoSortedLists(list1.getHead(), list2.getHead());

    node *current = mergedHead;
    while(current != nullptr){
        cout << current -> data << " -> ";
        current = current -> next;
    }
    cout << "x" << endl;

    return 0;
}