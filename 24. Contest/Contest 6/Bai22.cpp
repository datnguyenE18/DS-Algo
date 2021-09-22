#include<bits/stdc++.h>
using namespace std;

int a[1000001],n,x;
bool ok;

void solve()
{
	for (int i=0;i<n;i++) cin>>a[i];
	ok=false;
	int l=0, r=n-1;
	while (l<=r)
	{
		int m=(l+r)/2;
		if (a[m]>x) r=m-1;
		else
		if (a[m]<x) l=m+1;
		else
		if (a[m]==x)
		{
			ok=true;
			break;
		}
	}
	if (ok) cout<<"1"<<"\n";
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
