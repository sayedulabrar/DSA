#include<bits/stdc++.h>
using namespace std;

map<int, int> visited;
map<int, int> par;
map<int, int> dis;

int bfs(int x, int y){
    queue<int>q;
    q.push(x);
    visited[x]=1;
    par[x]=-1;
    dis[x]=0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i=1; i<=2; i++){
            int v = 2*u;
            if(i==2)    v = u-1;
            if(v==0 || visited[v]==1)    continue;
            q.push(v);
            visited[v]=1;
            dis[v]=dis[u]+1;
            par[v]=u;
            if(v==y)    return dis[v];
        }
    }
}

void path(int y){
    if(y==-1)   return;
    path(par[y]);
    if(par[y]==-1)  cout<<y<<" ";
    else    cout<<"-> "<<y<<" ";
}

int main(){
    int x,y;
    cin>>x>>y;
    cout<<bfs(x,y)<<endl;
    path(y);
}
