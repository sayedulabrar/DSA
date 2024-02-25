#include<bits/stdc++.h>
using namespace std;

struct Node{
    int id;
    int key;

    Node(){
    }

    Node (int i, int k){
        id = i;
        key = k;
    }
};

struct PriorityQueue{
    Node heap[105];
    int length;
    map<int, int> m;

    PriorityQueue(){
        length = 0;
    }

    ///Inserts a Node n in the min heap
    ///Where n.id = id and n.key = v
    bool insert(int id, int v){
        if(length==100)   return false;
        length++;
        Node n(id, v);
        heap[length]=n;
        m[id]=length;

        int i = length;
        while(i>1){
            int p = i/2;
            if(heap[p].key > heap[i].key){
                m[heap[p].id] = i;
                m[heap[i].id] = p;
                swap(heap[p],heap[i]);
                i = p;
                continue;
            }
            break;

        }
    }

    ///Returns and deletes the minimum node in the min heap
    Node extractMin(){
        if(length==0)   return Node(-1,9999);
        Node n = heap[1];
        heap[1] = heap[length];
        m[heap[1].id]=1;
        length--;

        int i =1;
        while(i<=length/2){
            int l = 2*i;
            int r = l + 1;

            Node minNode = heap[l];
            int minIndex = l;
            if(r<=length && heap[r].key < heap[l].key){
                minIndex = r;
                minNode = heap[r];
            }

            if(minNode.key < heap[i].key){
                m[minNode.id] = i;
                m[heap[i].id] = minIndex;
                swap(heap[i], heap[minIndex]);
                i = minIndex;
                continue;
            }
            break;
        }

        return n;
    }

    ///Decreases the value of a node n in the heap
    ///Where n.id = id and the updated n.key = v
    void decreaseKey(int id, int v){
        int i = m[id];
        heap[i].key = v;
        while(i>1){
            int p = i/2;
            if(heap[p].key > heap[i].key){
                m[heap[p].id] = i;
                m[heap[i].id] = p;
                swap(heap[p],heap[i]);
                i = p;
                continue;
            }
            break;

        }
    }

    ///Returns the size of the heap
    int size(){
        return length;
    }

    ///Prints the values of the heap level wise
    void print(){
        cout<<endl;
        int newLine = 2;
        for(int i=1; i<=length; i++){
            cout<<heap[i].key<<" ";
            if(i==newLine-1){
                cout<<endl;
                newLine*=2;
            }
        }
        cout<<endl<<endl;
    }

    ///Prints the ids and corresponding values of the heap level wise
    void showId(){
        cout<<endl;
        int newLine = 2;
        for(int i=1; i<=length; i++){
            cout<<"("<<heap[i].id<<", "<<heap[i].key<<") ";
            if(i==newLine-1){
                cout<<endl;
                newLine*=2;
            }
        }
        cout<<endl<<endl;
    }
};
