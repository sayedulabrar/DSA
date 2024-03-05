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
                //id is used to identify a node.So we have to swap the node and m's index for that node.
                m[heap[p].id] = i;
                m[heap[i].id] = p;
                swap(heap[p],heap[i]);
                i = p;
            }
            break;

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
                m[heap[smallest].id] = i;
                m[heap[i].id] = smallest;
                swap(heap[smallest],heap[i]);
                heapify(smallest);
    }
}


    ///Returns and deletes the minimum node in the min heap
    Node extractMin(){
        if(length==0)   return Node(-1,9999);
        Node n = heap[1];
        m.erase(heap[1].id);
        heap[1] = heap[length];
        m[heap[1].id]=1;
        
        length--;
        heapify(1);

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


    int getvalue(int i){
        return heap[m[i]].key;
    }
};

// void buildHeap(){
    

// for (int i = length / 2 ; i > 0; i--)
//         heapify(i);
// }


// void sort(){

//         buildHeap();
//         int xx=length;
//         for(int j=xx;j>=2;j--){

//             swap(a[j],a[1]);
//             n--;
//             heapify(1);

//         }
//         n=a[0].value;


// }
