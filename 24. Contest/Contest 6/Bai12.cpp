#include<bits/stdc++.h>
using namespace std;

long long a[1001],n,k;

void solve()
{
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for (int i=n-1;i>=n-k;i--) cout<<a[i]<<" ";
	cout<<"\n";
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
