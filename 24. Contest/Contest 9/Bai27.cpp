#include<bits/stdc++.h>
using namespace std;

vector <int> *a;
int v,e,ok[1001];

bool dfs(int u)
{
	ok[u]=1;
	for (int i=0;i<a[u].size();i++)
		if (ok[a[u][i]]==0)
		{
			ok[a[u][i]]=1;
			x=findp(u);
			y=find(a[u][i]);
			
		}
}

void solve()
{
	int x,y;
	for (int i=1;i<=e;i++)
	{
		cin>>x>>y;
		a[x].push_back(y);
	}
	memset(ok,0,sizeof(0));
	dfs(1);
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>v>>e;
		a=new vector <int> [1001];
		solve();
	}
}
