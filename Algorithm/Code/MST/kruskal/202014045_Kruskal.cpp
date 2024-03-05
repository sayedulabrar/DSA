#include<bits/stdc++.h>
using namespace std;
int parent[100];

struct check{
    int x,y,id;
    check(int a,int b,int c){
        x=a;
        y=b;
        id=c;
    }
}



    struct node{
    int x,y;
    int cost;
    node(){}
        node(int vv,int cc,int ee){x=vv; y=cc; cost=ee;}
    };

    bool comp(node aa,node bb)
    {
        return aa.cost<bb.cost;
    }
    vector<node>s;



int find(int x)
{
    if (x==parent[x]) return x;

    parent[x]=find(parent[x]);
    return parent[x];
}

void makeset(int i)
{
    parent[i]=i;
}

bool Union(int x, int y)
    {
        int xa = find(x);
        int ya = find(y);


        if (xa == ya)
            return false;

         parent[ya] = xa;
         return true;

    }






int main()
{
int n,v,a,b;


// kruskal's algorithm


cin>>n;
check am[n];
for(int i=0;i<n;i++)   //a,b is a point in xy axis.So a single makeset for it  with unique id i  i
{
    cin>>a>>b;
    check z(a,b,i);
    makeset(i);
    am[i]=z;

}

for(int i=0;i<n;i++)
{

    check zz=am[i];
    for(int j=0;j<n;j++)
    {
        check za=am[j];

        if(j!=i)
        {
           node d(zz.id,za.id,abs(zz.x-za.x)+abs(zz.y-za.y));
           s.push_back(d);

        }
    }

}
sort(s.begin(),s.end(),comp);
int bill=0;

for (auto ir = s.begin(); ir != s.end(); ++ir)
{
    node f=*ir;
    if(Union(f.x,f.y)){
        bill=bill+f.cost;
    }

cout<<bill<<endl;


}
}
