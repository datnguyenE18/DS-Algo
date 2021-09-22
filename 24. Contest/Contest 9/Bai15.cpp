#include<bits/stdc++.h>
using namespace std;

vector <int> *a;
long long ok[1001];
int v,e;

void dfs(int u)
{
	ok[u]=1;
	for (int i=0;i<a[u].size();i++)
		if (ok[a[u][i]]==0)
			dfs(a[u][i]);
}

int tplt()
{
	int d=0;
	for (int i=1;i<=v;i++)
		if (ok[i]==0)	
		{
			d++;
			dfs(i);
		}
	return d;
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
	cout<<tplt()<<"\n";
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>v>>e;
		a=new vector <int> [1001];
		solve(v,e);
		delete[] a;
	}
}
