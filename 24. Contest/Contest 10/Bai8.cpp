#include<bits/stdc++.h>
using namespace std;

struct tree
{
	int b;
	int e;
};

vector <int> *a;
vector <tree> t;
int v,e,u,ok[1001];

void dfs(int u)
{
	ok[u]=1;
	for (int i=0;i<a[u].size();i++)
		if (ok[a[u][i]]==0)
		{
			t.push_back({u,a[u][i]});
			dfs(a[u][i]);
		}
}

void solve()
{
	int x,y;
	bool check=true;
	for (int i=1;i<=e;i++)
	{
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(ok,0,sizeof(ok));
	dfs(u);
	if (t.size()==v-1)
	{
		for (int i=0;i<t.size();i++)
			cout<<t[i].b<<" "<<t[i].e<<"\n";
	}
	else cout<<"-1"<<"\n";
	t.clear();
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>v>>e>>u;
		a=new vector <int> [1001];
		solve();
	}
}
