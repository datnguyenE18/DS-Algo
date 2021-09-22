#include<bits/stdc++.h>
using namespace std;

long long a[100002],b[100002],c[100002];

void solve(int n,int m)
{
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[a[i]]++;
	}
	for (int i=1;i<=m;i++)
	{
		cin>>b[i];
		c[b[i]]++;
	}
	for (int i=0;i<=100000;i++) 
		if (c[i]!=0) cout<<i<<" ";
	cout<<"\n";
	for (int i=0;i<=100000;i++) 
		if (c[i]>1) cout<<i<<" ";
	cout<<"\n";
}

main()
{
	int t,n,m;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		cin>>n>>m;
		solve(n,m);
	}
}
