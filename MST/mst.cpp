#include<bits/stdc++.h>
#include "priorityQueue.h"
#define INF 9999
using namespace std;

int xx[105], yy[105];
int visited[105],key[105];
int n;

int abs(int x, int y){
    int m = x-y;
    if(m<0) return -m;
    return m;
}

int mstCost(int r){
    PriorityQueue pq;
    int total = 0;
    for(int i=0; i<n; i++){
        pq.insert(i,INF);
        key[i]=INF;
    }
    pq.decreaseKey(r, 0);  // r is id of root node
    key[r]=0;

    while(pq.size()!=0){
        Node uN = pq.extractMin();// It deletes the values so i must save it in key array.
        int u = uN.id;
        total+=uN.key;
        visited[u] = 1;

        for(int v=0; v<n; v++){ // it's because we are finding the most efficient path to connect the points in xy axis and no adjacent given.
            if(v==u)    continue;
            int w = abs(xx[u]-xx[v])+abs(yy[u]-yy[v]);
            if(visited[v]==0 && key[v] > w){  // for Dijkastra key[v]>w+key[u]
                pq.decreaseKey(v, w);
                key[v]=w; //key[v]=w+key[u]
            }
        }
    }
    return total;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++)  cin>>xx[i]>>yy[i];
    int cost = mstCost(0);
    cout<<cost<<endl;
}
///Test case 1
///Ans: 20
/*
5
0 0
2 2
3 10
5 2
7 0
*/


///Test case 2
///Ans: 4
/*
4
0 0
1 1
1 0
-1 1
*/