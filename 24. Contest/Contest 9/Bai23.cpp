#include<bits/stdc++.h>
using namespace std;

vector <int> *a;
int ok[1001];
bool cyc;

void dfs(int u)
{
	ok[u]=1;
	for (int i=0;i<a[u].size();i++)
		if (ok[a[u][i]]==0) dfs(a[u][i]);
		else 
		if (ok[a[u][i]]==1) cyc=true;
	ok[u]=2;
}

void solve(int v,int e)
{
	int x,y;
	for (int i=1;i<=e;i++)
	{
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(ok,0,sizeof(ok));
	cyc=false;
	for (int i=1;i<=v;i++)
		if (ok[i]==0) dfs(i);
	if (cyc) cout<<"YES"<<"\n";
	else cout<<"NO"<<"\n";
}

main()
{
	int t,v,e;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>v>>e;
		a=new vector <int> [1001];
		solve(v,e);
	}
}
