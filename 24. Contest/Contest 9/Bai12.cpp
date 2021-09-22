#include<bits/stdc++.h>
using namespace std;

vector <int> *a;
queue <int> b;
int ok[2000],p[2000];

void bfs(int u)
{
	ok[u]=1;
	b.push(u);
	while(!b.empty())
	{
		int s=b.front();
		for (int i=0;i<a[s].size();i++)
			if (ok[a[s][i]]==0) 
			{
				b.push(a[s][i]);
				ok[a[s][i]]=1;
				p[a[s][i]]=s;
			}
		b.pop();
	}
}

void path(int u,int v)
{
	stack <int> st;
	if (p[v]==0) cout<<"-1";
	else
	{
		st.push(v);
		int x=p[v];
		st.push(x);
		while (x!=u)
		{
			x=p[x];
			st.push(x);
		}
		while (!st.empty())
		{
			cout<<st.top()<<" ";
			st.pop();
		}
	}
	cout<<"\n";
}

void solve(int v,int e,int s,int t)
{
	int x,y;
	for (int i=1;i<=e;i++)
	{
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(ok,0,sizeof(ok));
	memset(p,0,sizeof(p));
	bfs(s);
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
