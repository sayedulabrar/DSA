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
    Node* findSuccessor(Node *node){
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

    void delete0Child(Node *node){
        if(node->parent==NULL)
        {
            free(node);
            root=NULL;
            return;
        }
        if(node->key<node->parent->key)
        {
            node->parent->left=NULL;
        }else if(node->key>node->parent->key)
        {
            node->parent->right=NULL;
        }
        free(node);




    }

    void delete1Child(Node *node){

        Node *dadu,*nati;

      dadu=node->parent;
      nati=node->left;
      if(nati==NULL){

        nati=node->right;
      }
      if(node==root)
        {
            root=nati;
            root->parent=NULL;
            free(node);
            return;
        }
      if(nati->key<dadu->key)
      {
          dadu->left=nati;
      }else
      {
          dadu->right=nati;
      }
      nati->parent=dadu;
      free(node);

    }

    void delete2Child(Node *node){
        Node *n,*m;
        n=findSuccessor(node->right);
        m=n->parent;
        node->key=n->key;
        if(n->left==NULL && n->right==NULL)
        {
           if(n->key<m->key)
        {
            m->left=NULL;
        }else
        {
            m->right=NULL;
        }
        }
        else
        {
         if(n->left==NULL || n->right==NULL)
            {
                delete1Child(n);
            }else{
            delete2Child(n);
            }
        }

        free(n);



    }

public:
    bool deleteNode(int val){
        Node *tmp=findNode(val);
        if(tmp==NULL)
        {
            return false;
        }else
        {
            if(tmp->left==NULL && tmp->right==NULL)
            {
                delete0Child(tmp);
            }else if(tmp->left==NULL || tmp->right==NULL)
            {
                delete1Child(tmp);
            }else{
            delete2Child(tmp);
            }
            return true;
        }

    }

    int height(Node *node){
        if(node==NULL)
        {
            return -1;
        }else
        {
            int lh,rh;
            lh=height(node->left);
            rh=height(node->right);
            return max(lh,rh) + 1;
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

