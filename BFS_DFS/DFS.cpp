#include<bits/stdc++.h>
using namespace std;

vector<int>a[100];///100 or nodes
bool visited[100];
int start[100];
int finish[100];
int t=1;
void dfs(int s)
{
    visited[s]=1;
    start[s]=t;
    t++;
    for(int i=0;i<a[s].size();i++)
    {
        if(visited[a[s][i]]==0)
        {
            dfs(a[s][i]);
        }
    }
    finish[s]=t;
    t++;
}
void checkdfs(int n)
{
    for(int i=0;i<n;i++)
    {
        if(visited[i]==1)
            cout<<i<<" KOP"<<endl;
        else
            cout<<i<<" MEH"<<endl;
    }
}
void print(int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<" -> ";
        for(int j=0;j<a[i].size();j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void showadj(int s)
{
    cout<<"adj of "<<s<<": ";
    for(int i=0;i<a[s].size();i++)
    {
        cout<<a[s][i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int nodes,edges,u,v;
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);

    }
    cout<<endl;
    print(nodes);
    cout<<endl;
    dfs(0);
    checkdfs(nodes);
    cout<<endl;
    showadj(3);
    cout<<endl;
}
///5 4 0 1 1 2 1 3 3 4
