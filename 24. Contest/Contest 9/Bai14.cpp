#include<bits/stdc++.h>
using namespace std;

vector <int> *a;
int ok[2000],p[1000];

void dfs(int u)
{
	ok[u]=1;
	for (int i=0;i<a[u].size();i++)
		if (ok[a[u][i]]==0)
		{
			p[a[u][i]]=u;
			dfs(a[u][i]);
		}
}

void solve(int v,int e)
{
	int x,y,q,s,t;
	for (int i=1;i<=e;i++)
	{
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	cin>>q;
	for (int i=1;i<=q;i++)
	{
		cin>>s>>t;
		memset(ok,0,sizeof(ok));
		memset(p,0,sizeof(p));
		dfs(s);
		if (p[t]==0) cout<<"NO"<<"\n";
		else cout<<"YES"<<"\n";
	}
}

main()
{
	int n,v,e;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>v>>e;
		a=new vector <int> [v+1];
		solve(v,e);
	}
}
