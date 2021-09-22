#include<bits/stdc++.h>
using namespace std;

vector <int> *a;
long long ok[1001];
int v,e;
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

int tplt()
{
	int d=0;
	for (int i=1;i<=v;i++)
		if (ok[i]==0)	
		{
			d++;
			bfs(i);
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
