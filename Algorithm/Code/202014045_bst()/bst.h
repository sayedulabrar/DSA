#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int key, level;
    Node *left, *right, *parent;
};


class BST{
private:
    Node *root;

public:
    BST(){
        root = NULL;
    }

    Node* getRoot() {return root;}


public:
    void insert(int val){
        Node *x,*y,*z;
        z=(Node*)malloc(sizeof(Node));
        z->key=val;
        z->left=NULL;
        z->right=NULL;
        z->parent=NULL;
        if(root==NULL)
        {
            root=z;
            return;
        }
        x=root;
        y=NULL;
        while(x!=NULL)
        {
            if(val<x->key){
                y=x;
                x=x->left;
            }else
            {
                y=x;
                x=x->right;
            }

        }
        z->parent=y;
        if(z->key<y->key)
        {
            y->left=z;
        }else
        {
            y->right=z;
        }


    }

    Node* findNode(int val){
         Node *n;
        n=root;
        while(n!=NULL && n->key!=val)
        {
            if(val<n->key){

                n=n->left;
            }else
            {
                n=n->right;
            }

            }
              return n;

        }



    Node* findMaximum(Node *node){
        if(node==NULL) return NULL;
        Node *n;
        n=node;
        while(n->right!=NULL)
        {
            n=n->right;

        }
        return n;

    }

    Node* findMinimum(Node *node){
        if(node==NULL) return NULL;
        Node *n;
        n=node;
        while(n->left!=NULL)
        {
            n=n->left;

        }
        return n;

    }

    void inOrder(Node *node){
        if(node==NULL) return;
        inOrder(node->left);
        cout<<node->key<<" ";
        inOrder(node->right);

    }

private:
    Node* findSuccessor(Node *node){// all about right
        Node *x,*y;
        if(node->right!=NULL)
        {
            return findMinimum(node->right);
        }else
        {
            x=node;
            y=node->parent;
            while(y!=NULL && y->right==x)
            {
                x=y;
                y=y->parent;
            }
            return y;
        }

    }


public:


Node* deleteNode(Node* root, int key) {
    // Base case: If the tree is empty or key not found
    if (root == NULL) 
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            if (temp)
                temp->parent = root->parent; // Update the parent pointer of the child
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            if (temp)
                temp->parent = root->parent; // Update the parent pointer of the child
            free(root);
            return temp;
        }

        Node* temp = minValueNode(root->right);   
        root->key = temp->key;
        root->right = deleteNode(temp, temp->key);
    }
    return root;
}
 
    int height(Node *node){
        if(node==NULL)
        {
            return -1;
        }else
        {
            return max(height(node->left),height(node->right)) + 1;
        }
    }


void bfs(){
    queue<Node*> q;
    root->level = 0;
    int level = root->level;
    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp->level > level){
            cout<<endl;
            level++;
        }
        cout<<temp->key<<" ";
        if(temp->left != NULL) {
            temp->left->level = temp->level + 1;
            q.push(temp->left);
        }
        if(temp->right != NULL) {
            temp->right->level = temp->level + 1;
            q.push(temp->right);
        }
    }
}

};

