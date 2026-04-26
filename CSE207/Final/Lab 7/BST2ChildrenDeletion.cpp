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

    node *findMin(node *Root){
        while(Root -> left != nullptr){
            Root = Root -> left;
        }
        return Root;
    }

    node* deletionChildrenNode(node *Root, int value){
        if(Root == nullptr){
            return nullptr;
        }

        if(value < Root -> data){
            Root -> left = deletionChildrenNode(Root -> left, value);
        }
        else if(value > Root -> data){
            Root -> right = deletionChildrenNode(Root -> right, value);
        }
        else{
            if(Root -> left != nullptr && Root -> right != nullptr){
                node *temp = findMin(Root -> right);
                Root -> data = temp -> data;
                Root -> right = deletionChildrenNode(Root -> right, temp -> data);
            }
            else if(Root -> left == nullptr){
                node *temp = Root->right;
                delete Root;
                return temp;
            }
            else if(Root -> right == nullptr){
                node *temp = Root->left;
                delete Root;
                return temp;
            }
        }

        return Root;
    }

    void deletionChildrenNode(int value){
        Root = deletionChildrenNode(Root, value);
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
    tree.Insertion(40);
    tree.Insertion(6);
    tree.Insertion(20);
    tree.Insertion(50);
    tree.Insertion(4);
    tree.Insertion(28);
    tree.Insertion(10);

    cout << "Insertion Complete" << endl;

    cout << "Inorder: " << endl;
    tree.inOrder(tree.getRoot());

    cout << endl;
    cout << "Preorder: " << endl;
    tree.preOrder(tree.getRoot());

    cout << endl;
    cout << "Postorder: " << endl;
    tree.postOrder(tree.getRoot());

    tree.deletionChildrenNode(6);
    tree.deletionChildrenNode(40);

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