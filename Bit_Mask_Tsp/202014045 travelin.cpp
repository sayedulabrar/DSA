#include<bits/stdc++.h>
using namespace std;


int a[10];
int b[10];
int vis[10];
double longest;
int number;

struct point
{
    int x;
    int y;
};
point p[10];

double dist(point m1,point m2)
{
    return sqrt((m1.x-m2.x)*(m1.x-m2.x)+(m1.y-m2.y)*(m1.y-m2.y));
}
void solve(int n,int x,double l)
{
    if( n==number-1)
    {
        if(longest>l)
        {

            longest=l;
            memcpy(b,a,sizeof(b));
        }
        return;
    }
    if(l>=longest)
        return;
    for(int i=0; i<number; i++)
    {
        if(vis[i]==0)
        {
            a[n+1]=i;
            vis[i]=1;
            solve(n+1,i,l+dist(p[x],p[i])+16);
            vis[i]=0;

        }
    }
}
int main()
{
    int ncase=0;
    while(cin>>number&&number)
    {
        for(int i=0; i<number; i++)
        {
            cin>>p[i].x>>p[i].y;
        }
        ncase++;
        longest=1<<31-1;
        for(int i=0; i<number; i++)
        {
            memset(vis,0,sizeof(vis));
            vis[i]=1;
            a[0]=i;
            solve(0,i,0.0);
        }
        double ans=0;
        cout<<"**********************************************************"<<endl;
        cout<<"Network#"<<ncase<<endl;
            for(int i=1; i<number; i++)
        {
            double tmp=dist(p[b[i]],p[b[i-1]])+16;
            cout<<"cable required to connect ("<<p[b[i-1]].x<<" "<<p[b[i-1]].y<<") to ("<<p[b[i]].x<<" "<<p[b[i]].y<<")  is "<<tmp<<"feet"<<endl;
            ans=ans+tmp;
        }
        cout<<"Number of feet of cable required is "<<longest<<" feet"<<endl;
    }
    return 0;
}
