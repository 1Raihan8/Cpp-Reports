#include <bits/stdc++.h>
using namespace std;

int main(){
    // Vector Commonly Used Member Functions

    // size()
    vector<int> v1;
    cout << "Length of v1: " << v1.size() << endl;

    vector<int> v2 = {1, 2, 3};
    cout << "Length of v2: " << v2.size() << endl;

    // push_back(x)
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);  // v = {10, 20, 30, 40}
    cout << "Length: of v: " << v.size() << endl;

    // pop_back()
    v.pop_back(); // v = {10, 20, 30}
    cout << "Length: of v: " << v.size() << endl;

    // clear()
    v.clear(); // v is empty
    cout << "Length: of v: " << v.size() << endl;

    // empty()
    if (v.empty()) {
        cout << "Vector is empty" << endl;
    }

    // begin()
    vector<int> v3 = {10, 20, 30};
    cout << *v3.begin() << endl;   // Output: 10

    // end()
    cout << *v3.end() << endl;   // Output: 30

    // erase()
    vector<int> v4 = {10, 20, 30, 40};
    v4.erase(v4.begin() + 1); // v = {10, 30, 40}

    // insert()
    v4.insert(v4.begin() + 1, 15); // v = {10, 15, 30, 40}

    // Stack Commonly Used Member Functions

    // empty()
    stack<int> s;
    if (s.empty()) {
        cout << "Stack is empty" << endl;
    }

    // push(x)
    stack<int> s1;
    s1.push(10);
    s1.push(20); // s1 = {10, 20}

    // size()
    cout << s1.size() << endl; // 2
    
    // pop()
    s1.pop(); // s1 = {10}

    // top()
    stack<int> s2;
    s2.push(100);
    s2.push(200);

    cout << s2.top() << endl; // 200

    // Queue Commonly Used Member Functions

    //empty()
    queue<int> q;
    if (q.empty()) {
        cout << "Queue is empty" << endl;
    }

    // push(x)
    q.push(10);
    q.push(20);

    // size()
    cout << q.size() << endl; // 2

    // pop()
    q.pop(); // q = {10}

    // front()
    queue<int> q1;
    q1.push(100);
    q1.push(200);

    cout << q1.front() << endl; // 100

    // back()
    cout << q1.back() << endl; // 200

    return 0;
}