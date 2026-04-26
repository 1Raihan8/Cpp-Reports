#include <bits/stdc++.h>
using namespace std;

class Heap{
    int heap[100];
    int N;
    int len;
public:
    Heap(){
        this -> N = 100;
        this -> len = 0;
    }

    void insert(int value){
        if(len == N){
            cout << "Overflows!" << endl;
            return;
        }

        len++;
        heap[len] = value;
        int index = len;
        while(index > 1 && heap[index/2] < heap[index]){
            swap(heap[index/2], heap[index]);
            index = index/2;
        }
    }

    void print(){
        for(int i = 1; i <= len; i++){
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Heap h;
    h.insert(53);
    h.insert(44);
    h.insert(25);
    h.insert(15);
    h.insert(21);
    h.insert(13);
    h.insert(18);

    h.print();
    return 0;
}