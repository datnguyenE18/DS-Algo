#include<bits/stdc++.h>
using namespace std;

vector <int> *a;
int ok[1000];
queue <int> b;

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
				ok[a[s][i]]=1;
				b.push(a[s][i]);
			}
		b.pop();
	}
}

bool lt(int v)
{
	for (int i=1;i<=v;i++)
		if (ok[i]==0) return false;
	return true;
}

bool tru(int u,int v)
{
	memset(ok,0,sizeof(ok));
	ok[u]=1;
	if (u==1) bfs(2);
	else bfs(1);
	if (!lt(v)) return true;
	else return false;
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
	for (int i=1;i<=v;i++)
		if (tru(i,v)) cout<<i<<" ";
	cout<<"\n";
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
		delete[] a;
	}
}
