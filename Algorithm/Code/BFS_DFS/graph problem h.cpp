#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int vis[1100];
int prime[1100];
int dis[1100];
int s,t,p=1200;

void get_prime()
{
	for(int i=2;i*i<=1100;i++)
	{
		if(!prime[i])
		{
			for(int j=i*i;j<=1100;j+=i)
				prime[j]=1;
		}
	}
}


int bfs()
{
    memset(vis,0,sizeof(vis));
	queue<int>q;
	int now,nextt;
	dis[s]=0;
	q.push(s);

	while(!q.empty())
	{
		now=q.front();
		q.pop();

       if(now==t)
        {
            return dis[now];
        }

		for(int i=2;i<now;i++)
		{
			if(now%i==0&&!prime[i])
			{
			    if(now+i<=t&&vis[now+i]!=1)
                {
                  nextt=now+i;
                  dis[nextt]=dis[now]+1;
                  vis[nextt]=1;
				q.push(nextt);

                }



			}
		}




	}
	return -1;
}

int main()
{
	int T,k=1,xx;
	get_prime();
	cin>>T;
	while(T--)
	{
		cin>>s>>t;
		xx=bfs();

            cout<<"Case "<<k<<": "<<xx<<endl;

        k++;
        p=1200;

	}
	return 0;
}

