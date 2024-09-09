#include<bits/stdc++.h>
using namespace std;

map<string, int> visited;
map<string, int> dis;
map<string, string> par;
map<string, vector<string> >adj;

void bfs(){
    queue<string>q;
    q.push("C:");
    visited["C:"]=1;
    dis["C:"]=0;
    par["C:"]="-1";

    while(!q.empty()){
        string u = q.front();
        q.pop();
        int len = adj[u].size();

        for(int i=0; i<len; i++){
            string v = adj[u][i];
            if(visited[v]!=1){
             q.push(v);
             visited[v]=1;
             par[v]=u;
             dis[v]=dis[u]+1;
            }

        }
    }
}

void path(string x){
    if(x=="-1") return;
    path(par[x]);
    if(x=="C:") cout<<"C:";
    else    cout<<"\\\\"<<x;
}

int main(){
    int e;
    cin>>e;
    while(e--){
        string x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    bfs();
    int q;
    cin>>q;
    while(q--){
        string x;
        cin>>x;
        if(visited[x]==0){
            cout<<"File not found"<<endl<<"-1"<<endl;
            continue;
        }
        path(x);
        cout<<endl<<dis[x]*2<<endl;
    }
}
