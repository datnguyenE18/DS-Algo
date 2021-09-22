#include<bits/stdc++.h>
using namespace std;

long long n,s,c,x;

void solve()
{
	s=0; c=0;
	for (int i=1;i<n;i++)
	{
		cin>>x;
		s=s+x;
	}
	c=n*(n+1)/2;
	cout<<c-s<<"\n";
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
