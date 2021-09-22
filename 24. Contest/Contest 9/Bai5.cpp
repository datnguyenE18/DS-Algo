#include<bits/stdc++.h>
using namespace std;

typedef vector <int> adj;

void solve(int v,int e)
{
	int x,y;
	vector <adj> a(v+1);
	for (int i=1;i<=e;i++)
	{
		cin>>x>>y;
		a[x].push_back(y);
	}
	for (int i=1;i<=v;i++)
	{
		cout<<i<<": ";
		for (int j=0;j<a[i].size();j++) 
			cout<<a[i][j]<<" ";
		cout<<"\n";
	}
}

main()
{
	int t,v,e;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>v>>e;
		solve(v,e);
	}
}
