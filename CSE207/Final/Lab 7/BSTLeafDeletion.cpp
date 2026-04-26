#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
    node(int a = 0){
        this -> data = a;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};

class BST{
    node *Root;
public:
    BST(){
        this -> Root = nullptr;
    }

    node* getRoot(){
        return Root;
    }

    node* Insertion(node *Root, int value){
        if(Root == nullptr){
            node *newNode = new node(value);
            return newNode;
        }

        if(value < Root -> data){
            Root -> left = Insertion(Root -> left, value);
        }
        else if(value > Root -> data){
            Root -> right = Insertion(Root -> right, value);
        }

        return Root;
    }

    void Insertion(int value){
        Root = Insertion(Root, value);
    }

    node* deletion(node *Root, int value){
        if(Root == nullptr){
            return nullptr;
        }

        if(value < Root -> data){
            Root -> left = deletion(Root -> left, value);
        }
        else if(value > Root -> data){
            Root -> right = deletion(Root -> right, value);
        }
        else{
            if(Root -> left == nullptr && Root -> right == nullptr){
                delete Root;
                return nullptr;
            }
        }

        return Root;
    }

    void deletion(int value){
        Root = deletion(Root, value);
    }

    void inOrder(node *Root){
        if(Root == nullptr){
            return;
        }

        inOrder(Root -> left);
        cout << Root -> data << " ";
        inOrder(Root -> right);
    }

    void preOrder(node *Root){
        if(Root == nullptr){
            return;
        }

        cout << Root -> data << " ";
        preOrder(Root -> left);
        preOrder(Root -> right);
    }

    void postOrder(node *Root){
        if(Root == nullptr){
            return;
        }

        postOrder(Root -> left);
        postOrder(Root -> right);
        cout << Root -> data << " ";
    }
};

int main(){
    BST tree;
    tree.Insertion(32);
    tree.Insertion(52);
    tree.Insertion(12);
    tree.Insertion(3);
    tree.Insertion(65);
    tree.Insertion(11);

    cout << "Insertion Complete" << endl;

    cout << "Inorder: " << endl;
    tree.inOrder(tree.getRoot());

    cout << endl;
    cout << "Preorder: " << endl;
    tree.preOrder(tree.getRoot());

    cout << endl;
    cout << "Postorder: " << endl;
    tree.postOrder(tree.getRoot());

    tree.deletion(11);
    tree.deletion(65);

    cout << endl << endl;

    cout << "Inorder: " << endl;
    tree.inOrder(tree.getRoot());

    cout << endl;
    cout << "Preorder: " << endl;
    tree.preOrder(tree.getRoot());

    cout << endl;
    cout << "Postorder: " << endl;
    tree.postOrder(tree.getRoot());

    return 0;
}