#include<bits/stdc++.h>
using namespace std;

//typedef vector <int> adj;
vector <int> *a;
int ok[3000];

void dfs(int u)
{
	cout<<u<<" ";
	ok[u]=1;
	for (int i=0;i<a[u].size();i++)
		if (ok[a[u][i]]==0) dfs(a[u][i]);
}

void solve(int v,int e,int u)
{
	int x,y;
	for (int i=1;i<=e;i++)
	{
		cin>>x>>y;
		a[x].push_back(y);
	}
	memset(ok,0,sizeof(ok));
	dfs(u);
	cout<<"\n";
}

main()
{
	int t,v,e,u;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>v>>e>>u;
		a=new vector <int> [v+1];
		solve(v,e,u);
	}
}
