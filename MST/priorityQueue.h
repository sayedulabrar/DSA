#include<bits/stdc++.h>
using namespace std;

// id is used to connect <source,destination> and weight with id ,<source,destination> and id,weight.
// This way we can use id, weight in priority queue easily and don't worry about <source,destination>
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
    map<int, int> m;////Without the map, you would need to search through the entire heap array to find the index of a specific node when performing operations like decreasing the key .

    PriorityQueue(){
        length = 0;
    } 


    void swap(Node* a,Node* b){
        swap(a.id,b.id);
        swap(a.value,b.value);
        int indexa=m[a.id];
        int indexb=m[b.id];
        m[a.id]=indexb;
        m[b.id]=indexa;
    }

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
                swap(heap[p],heap[i]);               
                i = p;
            }else break;

        }
    }


void heapify(int i)
{
    n=length;
    int smallest = i;
    int l = 2 * i;
    int r = 2 * i + 1;


    if (l <= n && heap[l].value < heap[smallest].value)
        smallest = l;

    if (r <= n && heap[r].value < heap[smallest].value)
        smallest = r;

    if (smallest != i) {
                swap(heap[smallest],heap[i]);
                heapify(smallest);
    }
}

    Node extractMin(){
        if(length==0)   return Node(-1,9999);
        Node n = heap[1];
        swap(heap[1], heap[length]);
        length--;
        heapify(1);
        return n;

    }


    void decreaseKey(int id, int v){
        int i = m[id];
        heap[i].key = v;
        while(i>1){
            int p = i/2;
            if(heap[p].key > heap[i].key){
                swap(heap[p],heap[i]);
                i = p;
            }else break;

        }

    }

    ///Returns the size of the heap
    int size(){
        return length;
    }

    ///Prints the values of the heap level wise
    void print(){

        int newLine = 1;
        for(int i=1; i<=length; i++){
            if(i==newLine){
                cout<<endl;
                newLine*=2;
            }
            cout<<heap[i].key<<" ";

        }      
        cout<<endl<<endl;
    }

};

void buildHeap(){

for (int i = length / 2 ; i > 0; i--)
        heapify(i);
}


void sort(){
        buildHeap();
        int xx=length;
        for(int j=xx;j>=2;j--){
            swap(a[j],a[1]);
            heapify(1);
        }
}



// only when a single node defies heap property then heapify can work . Heapify goes throuh a sigle path by selecting it everytime. So it can 
//handle only one . but not if multiple node defies heap property.
// So it only works for extractMin and sort as it is done one by one.

//why did we not call heapify in decreaseKey? Because it is minheap and parent is always less than child .So no need for heapify .Just flow up.

    // Inserts a Node n in the min heap
    // Where n.id = id and n.key = v

    // Why do we insert at length? 
    // Because heap only ensures parent > or < the children based on type of heap.So it does not
    // care if l>r or r>l anything at all.So we insert it at length and at that time parent is highest.So if new element is less than highest it will 
    // be stuck under parent but if  bigger it will flow up and replace parent and become new hiGhest.That is why it does not matter if we insert it 
    // at length as it only cares about parent being dominant.