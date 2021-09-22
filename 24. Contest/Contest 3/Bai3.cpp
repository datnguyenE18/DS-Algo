#include<bits/stdc++.h>
using namespace std;

#define max 1000000007

long long a[10000000],n;

void timmax()
{
	long long smax=0;
	sort(a,a+n);
	for (long long i=0;i<n;i++)
	{
		smax=(smax%max)+((i*a[i])%max);
		smax=smax%max;
	}
	cout<<smax<<"\n";	
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n;
		for (long long j=0;j<n;j++) cin>>a[j];
		timmax();
	}
}
