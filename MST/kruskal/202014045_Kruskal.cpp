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
    return  parent[x]=find(parent[x]);//karon parent update hobe prottek node er returned node use kore.so
    // find(parent[x]) use kore upore jasse chain er and directly update korte parent[x]=find(parent[x]) approch nise.
    //path compression
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
    am[i]=z;
    makeset(i);//make set based on  index as it's unique.

}

for(int i=0;i<n;i++)
{

    par zz=am[i];
    for(int j=i+1;j<n;j++)
    {
        par za=am[j];


           node d(i,j,abs(zz.x-za.x)+abs(zz.y-za.y));  //use index to make edge and weight which is correct as makeset was based on index.
           s.push_back(d);

    }

}   
sort(s.begin(),s.end(),comp);
int bill=0;

for (int ir=0; ir<s.size();ir++)
{
    node f=s[ir];
    if(Union(f.x,f.y))
    {
        bill=bill+f.cost;
    }
}

cout<<bill<<endl;


}
