#include<bits/stdc++.h>
using namespace std;

int a[21],n;

void solve()
{
	long long x=0,y=0;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for (int i=0;i<n;i++)
		if (i%2==0) x=x*10+a[i];
		else y=y*10+a[i];
	cout<<x+y<<"\n";
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
