#include<bits/stdc++.h>
using namespace std;

vector <int> *a;
int ok[1001],v,e;

void dfs(int u)
{
	ok[u]=1;
	for	(int i=0;i<a[u].size();i++)
		if (ok[a[u][i]]==0) dfs(a[u][i]);
}

bool lt(int u)
{
	memset(ok,0,sizeof(ok));
	dfs(u);
	for (int i=1;i<=v;i++)
		if (ok[i]==0) return false;
	return true;
}

bool stronglt()
{
	for (int i=1;i<=v;i++)
		if (!lt(i)) return false;
	return true;
}

void solve()
{
	int x,y;
	for (int i=1;i<=e;i++)
	{
		cin>>x>>y;
		a[x].push_back(y);
	}
	if (stronglt()) cout<<"YES"<<"\n";
	else cout<<"NO"<<"\n";
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
		delete[] a;
	}
}
