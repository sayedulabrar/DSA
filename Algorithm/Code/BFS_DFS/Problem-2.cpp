#include<bits/stdc++.h>
using namespace std;

int color[100];  ///0 means no color, 1 means color-1, 2 means color-2
vector<int>adj[100];

int bfs(int s){
    color[s]=1;
    queue<int>q;
    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        int len = adj[u].size();

        for(int i=0; i<len; i++){
            int v = adj[u][i];
            if(color[u]==color[v])  return -1;
            if(color[v]==0){
                color[v]=1;
                if(color[u]==1) color[v]=2;
                q.push(v);
            }
        }
    }
    return 0;
}

int main(){
    int n,e;
    cin>>n>>e;
    for(int i=1; i<=e; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=0; i<n; i++){
        if(color[i]==0){
            int c = bfs(i);
            if(c==-1){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
}
