#include<bits/stdc++.h>
using namespace std;
const long long m=1e9+7;

priority_queue <long long,vector<long long>,greater<long long> > a;
long long n,s,d;

void solve()
{
	long long x;
	d=0;
	for (int i=0;i<n;i++) 
	{
		cin>>x;
		a.push(x);
	}
	while(a.size()!=1)
	{
		long long x1=a.top();
		a.pop();
		long long x2=a.top();
		a.pop();
		long long x=(x1+x2)%m;
		a.push(x);
		d=(d+x)%m;
	}
	cout<<d<<"\n";	
	a.pop();
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
