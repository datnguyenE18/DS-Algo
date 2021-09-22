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

void bfs(int u)
{
	queue <int> s;
	s.push(u);
	ok[u]=1;
	while (!s.empty())
	{
		int x=s.front();
		s.pop();
		for (int i=0;i<a[x].size();i++)
			if (ok[a[x][i]]==0)
			{
				ok[a[x][i]]=1;
				s.push(a[x][i]);
				t.push_back({x,a[x][i]});
			}
	}
}

void solve()
{
	int x,y;
	for (int i=1;i<=e;i++)
	{
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(ok,0,sizeof(ok));
	bfs(u);
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
