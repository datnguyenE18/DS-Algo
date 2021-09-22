#include<bits/stdc++.h>
using namespace std;

long long a[1001],n,mi,s;

void solve()
{
	for (int i=0;i<n;i++) cin>>a[i];
	mi=1000001;
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if (mi>abs(a[i]+a[j]))
			{
				mi=abs(a[i]+a[j]);
				s=a[i]+a[j];
			}
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
