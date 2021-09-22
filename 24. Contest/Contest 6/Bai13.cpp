#include<bits/stdc++.h>
using namespace std;

long long a[1000001],n,x,k;

void solve()
{
	memset(a,0,sizeof(a));
	for (int i=0;i<n;i++) 
	{
		cin>>k;
		a[k]++;
	}
	if (a[x]!=0) cout<<a[x]<<"\n";
	else cout<<"-1"<<"\n";
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n>>x;
		solve();
	}
}
