#include<bits/stdc++.h>
using namespace std;

int len,k;
void prmt(string s, int n)
{
    if(!n)
    {
        cout<<s<<"\n";
        k--;
        return;
    }

    string ns = s;
    for(char c='A'; c<'A'+len; c++)
    {
        int f=0;

        for(int i=0; i<ns.size(); i++)
        {
            if(ns[i]==c) f++;
        }

        if(!f)
        {
            ns+= c;
            prmt(ns,n-1);
            if(!k) break;
            ns.pop_back();
        }
    }
}

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t,i=0;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n>>k;
        cout<<"Case "<<++i<<":\n";
        len = n;
        string s;
        prmt(s,n);
    }
    return 0;
}
