#include<bits/stdc++.h>
using namespace std;

long long n,a[10000000],b[10000000],s;

void solve()
{
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++) cin>>b[i];
	s=0;
	sort(a,a+n);
	sort(b,b+n);
	for (int i=0;i<n;i++) s=s+a[i]*b[n-i-1];
	cout<<s<<"\n";
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n;
		solve();
	}
}
