#include<bits/stdc++.h>
using namespace std;

int a[100001],n,m,x,maxi;

void solve(int n,int m)
{
	memset(a,0,sizeof(a));
	maxi=0;
	for (int i=1;i<=n+m;i++)
	{
		cin>>x;
		a[x]++;
		if (x>maxi) maxi=x;
	}
	for (int i=0;i<=maxi;i++)
		if (a[i]>=1) cout<<i<<" ";
	cout<<"\n";
	for (int i=0;i<=maxi;i++)
		if (a[i]>1) cout<<i<<" ";
	cout<<"\n";	
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n>>m;
		solve(n,m);
	}
}
