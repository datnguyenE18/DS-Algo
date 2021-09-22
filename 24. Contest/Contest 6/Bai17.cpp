#include<bits/stdc++.h>
using namespace std;

long long x,mi,ma,m,n,s;

void solve()
{
	mi=100000000; ma=-100000000;
	for (int i=0;i<n;i++) 
	{
		cin>>x;
		if (ma<x) ma=x;
	}
	for (int i=0;i<m;i++) 
	{
		cin>>x;
		if (mi>x) mi=x;
	}
	s=mi*ma;
	cout<<s<<"\n";
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n>>m;
		solve();
	}
}
