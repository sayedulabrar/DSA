#include<bits/stdc++.h>
using namespace std;

void bfs(int n){
    queue<string>q;
    q.push("");
    int lev = -1;
    while(!q.empty()){
        int size=q.size();
        lev++;
        cout<<"Length "<<lev<<" : "
    if(lev==3){ 
        q.empty();
        break; 
    }
    for(int i=0;i<size;i++){
        string u = q.front();
        q.pop();
        string r=u+"0";
        string l=u+"1";
        cout<<r<<","<<l<<",";
        q.push(r);
        q.push(l);
    }
    cout<<endl;

}
}

int main(){
    int n;
    cin>>n;
    bfs(n);
}
