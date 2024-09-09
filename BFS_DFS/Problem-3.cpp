#include<bits/stdc++.h>
using namespace std;


Akhon 1st je destination pousae oe oikhanei block kore dae visit= 1 kore. so overrite chance nai.
int dx[8]={1,-1,1,-1,-2,-2,2,2};
int dy[8]={-2,-2,2,2,1,-1,1,-1};

struct Move{
    int r,c;
    Move(int x, int y){
        r=x;
        c=y;
    }

    Move(){}
};

void print(Move p){
    int i = p.r;
    int j = p.c;
    cout<<(char)(i+97)<<j+1<<" ";
}

int bfs(int si, int sj, int di, int dj){
    queue<Move>q;
    int visited[8][8]={0};
    int dis[8][8]={0};
    Move parent[8][8];
    Move s(si,sj);
    visited[si][sj]=1;
    q.push(s);
    Move p(-1,-1);
    parent[si][sj]=p;

    while(!q.empty()){
        Move u = q.front();
        q.pop();
        int ur = u.r;
        int uc = u.c;
        for(int i=0; i<8; i++){
            int vr = ur + dx[i];
            int vc = uc + dy[i];
            Move v(vr,vc);
            if(vr<0 || vr>7 || vc<0 || vc>7 || visited[vr][vc]==1)  continue;
            q.push(v);
            visited[vr][vc]=1;
            dis[vr][vc]=dis[ur][uc]+1;
            parent[vr][vc]=u;
        }
    }

    Move d(di,dj);
    while(d.r==-1){
        print(d);
        d = parent[d.r][d.c];
    }
    return dis[di][dj];
}



int main(){
    int t;
    string x,y;
    cin>>t;
    while(t--){
        cin>>x>>y;
        int si = (int)x[0]-97;
        int sj = (int)x[1]-49;
        int di = (int)y[0]-97;
        int dj = (int)y[1]-49;

        int dis = bfs(si,sj,di,dj);
        cout<<"To get from "<<x<<" to "<<y<<" takes "<<dis<<" knight moves."<<endl;
    }
}
