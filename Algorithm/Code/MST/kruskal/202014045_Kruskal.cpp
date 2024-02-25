#include<bits/stdc++.h>
using namespace std;
int parent[100];




struct par{
    int x,y;
    par(){}
        par(int vv,int cc){x=vv; y=cc;}
    };

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

    int r=find(parent[x]);
    parent[x]=r;
    return r;
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
par am[n];
for(int i=0;i<n;i++)
{
    cin>>a>>b;
    par z(a,b);
    makeset(a);
    am[i]=z;

}

for(int i=0;i<n;i++)
{

    par zz=am[i];
    for(int j=0;j<n;j++)
    {
        par za=am[j];

        if(j!=i)
        {
           node d(zz.x,za.x,abs(zz.x-za.x)+abs(zz.y-za.y));
           s.push_back(d);

        }
    }

}
sort(s.begin(),s.end(),comp);
int bill=0;

for (auto ir = s.begin(); ir != s.end(); ++ir)
{
    node f=*ir;
    if(find(f.x)!=find(f.y))
    {
        Union(f.x,f.y);
        bill=bill+f.cost;
    }
}

cout<<bill<<endl;


}
