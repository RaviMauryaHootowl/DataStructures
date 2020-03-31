#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *leftChild;
    node *rightChild;
};

class BinaryTree
{
private:
    node *root;

public:
    BinaryTree()
    {
        root = NULL;
    }

    void insert(int n){
        if(root == NULL){
            root = new node();
            root->data = n;
            root->leftChild = NULL;
            root->rightChild = NULL;
        }else{
            insert(n, root);
        }
    }

    void insert(int n, node* leaf){
        if(n < leaf->data){
            if(leaf->leftChild != NULL){
                insert(n, leaf->leftChild);
            }else{
                leaf->leftChild = new node;
                leaf->leftChild->data = n;
                leaf->leftChild->leftChild = NULL;
                leaf->leftChild->rightChild = NULL;
            }
        }else if(n >= leaf->data){
            if(leaf->rightChild != NULL){
                insert(n, leaf->rightChild);
            }else{
                leaf->rightChild = new node;
                leaf->rightChild->data = n;
                leaf->rightChild->leftChild = NULL;
                leaf->rightChild->rightChild = NULL;
            }
        }
    }

    void inorder_print(){
        //cout << root->leftChild->data << endl;
        inorder_print(root);
        cout << "\n";
    }

    void inorder_print(node* leaf){
        if(leaf != NULL){
            inorder_print(leaf->leftChild);
            cout << leaf->data << " ";
            inorder_print(leaf->rightChild);
        }
    }
};

int main()
{

    BinaryTree bt;
    bt.insert(5);
    bt.insert(2);
    bt.insert(8);
    bt.inorder_print();
    return 0;
}