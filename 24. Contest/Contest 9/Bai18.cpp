#include<bits/stdc++.h>
using namespace std;

vector <int> *a;
int ok[1001],v,e;
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

bool lt(int u)
{
	memset(ok,0,sizeof(ok));
	bfs(u);
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
