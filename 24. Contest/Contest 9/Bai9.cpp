#include<bits/stdc++.h>
using namespace std; 

vector <int> *a;
queue <int> b;
int ok[2000];

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
			}
		cout<<s<<" ";
		b.pop();
	}
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
	bfs(u);
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
