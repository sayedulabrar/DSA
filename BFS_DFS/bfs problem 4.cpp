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


    void inOrder(Node *node){
        if(node==NULL) return;
        cout<<node->key<<" ";
        inOrder(node->left);
        inOrder(node->right);

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
            if(temp->left!=NULL){
                if(temp->left!=root)  temp->left->level = temp->level + 1;
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                if(temp->right!=root)  temp->right->level = temp->level + 1;
                q.push(temp->right);
            }
        }
    }
};

int main(){
    BST b;
    int m,n,o,p;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int y;
        cin>>y;
        b.insert(y);
    }
    b.bfs();
}







