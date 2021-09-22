#include<bits/stdc++.h>
using namespace std;

vector <int> *a;
int ok[2000],p[2000];

void path(int s,int t)
{
	stack <int> r;
	if (p[t]==0) cout<<"-1"<<"\n";
	else
	{
		r.push(t);
		int u=p[t];
		while (u!=s)
		{
			r.push(u);
			u=p[u];
		}
		r.push(s);
	while (!r.empty())
	{
		cout<<r.top()<<" ";
		r.pop();
	}
	cout<<"\n";
	}
}

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

void solve(int v,int e,int s,int t)
{
	int x,y;
	for (int i=1;i<=e;i++)
	{
		cin>>x>>y;
		a[x].push_back(y);
	}
	memset(ok,0,sizeof(ok));
	memset(p,0,sizeof(p));
	dfs(s);
	path(s,t);
}

main()
{
	int n,v,e,s,t;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>v>>e>>s>>t;
		a=new vector <int> [v+1];
		solve(v,e,s,t);
	}
}
