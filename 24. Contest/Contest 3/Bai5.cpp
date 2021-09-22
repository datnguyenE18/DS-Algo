#include<bits/stdc++.h>
using namespace std;

int n,k,a[60];

void solve()
{
	long long s=0,x=0,y=0;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for (int i=0;i<n;i++) s=s+a[i];
	for (int i=0;i<k;i++) x=x+a[i];
	for (int i=0;i<n-k;i++) y=y+a[i];
	cout<<max((s-2*x),(s-2*y))<<"\n";
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n>>k;
		solve();
	}
}
