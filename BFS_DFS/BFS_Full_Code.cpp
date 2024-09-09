#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

int n,e;
int adj[100][100];
int dis[100];
int par[100];
int visited[100];

void init(){
    for(int i=0; i<n; i++){
        dis[i]=INF;
        par[i]=-1;
        visited[i]=0;
        for(int j=0; j<n; j++){
            adj[i][j]=0;
        }
    }
    return;
}

void bfs(int s){
    dis[s]=0;
    queue<int>q;
    q.push(s);
    visited[s]=1;

    while(q.size()!=0){
        int king = q.front();
        q.pop();

        ///This for loop is used to traverse all the vertices of the graph
        for(int child=0; child<n; child++){
            ///This "if" is used to filter the vertices that are adjacent to "king"
            if(adj[king][child]==1){

                ///This "if" is used to filter the unvisited adjacent of "king"
                if(visited[child]==0){
                    q.push(child);
                    visited[child]=1;
                    dis[child]=dis[king]+1;
                    par[child]=king;
                }
            }
        }
    }

    return;
}

void path(int x){ ///It prints the path of x
    if(x==-1)   return;
    path(par[x]);
    if(par[x]==-1)  cout<<x;
    else    cout<<"->"<<x;
    return;
}

int main(){
    cin>>n;
    init();
    cin>>e;

    for(int i=1; i<=e; i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }

    bfs(5);  ///Assuming 5 as source

    ///Print the level(minimum distance from source) of all the vertices
    for(int v=0; v<n; v++){
        cout<<"Distance of "<<v<<" from source is: "<<dis[v]<<endl;
    }


    ///Print the path of all vertices
    for(int v=0; v<n; v++){
        cout<<"Path of "<<v<<" is: ";
        path(v);
        cout<<endl;
    }
}

/*
6 7

5 1
0 1
0 3
1 3
4 3
5 4
3 5
*/
