#include<bits/stdc++.h>
using namespace std;

void bfs(int n){
    queue<string>q;
    q.push("");
    int lev = 0;
    while(!q.empty()){
        string u = q.front();
        q.pop();
        if(u.size()!=0){
            if(lev!=u.size()){
                cout<<endl<<"Length "<<u.size()<<": ";
                lev++;
            }
            cout<<u<<" ";
        }

        if(u.size()==n) continue;
        q.push(u+"0");
        q.push(u+"1");
    }
}

int main(){
    int n;
    cin>>n;
    bfs(n);
}
