#include<bits/stdc++.h>
using namespace std;

long long m,n,a[1000001];

void solve()
{
	for (int i=0;i<n+m;i++) cin>>a[i];
	sort(a,a+m+n);
	for (int i=0;i<n+m;i++) cout<<a[i]<<" ";
	cout<<"\n";
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
