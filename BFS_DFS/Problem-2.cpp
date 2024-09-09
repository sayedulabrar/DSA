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
            if(color[v]==0){
                if(color[u]==1) color[v]=2;
                else if(color[u]==2) color[v]=1;
                q.push(v);
            }else
            {
                if(color[u]==color[v])  return -1; //2nd time visit not allowed .So if it's visited it won't be pushed or colored.
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

    for(int i=0; i<n; i++){ // to handle forest.multiple seperate trees.
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
