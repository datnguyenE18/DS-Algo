#include<bits/stdc++.h>
using namespace std;

int tinh(int n,long long k)
{
	if (k%2==1) return 1;
	long long x=pow(2,n-1);
	if (k==x) return n;
	if (k<x) return tinh(n-1,k);
	return tinh(n-1,k-x);
}

main()
{
	int t,n;
	long long k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		cout<<tinh(n,k)<<"\n";
	}
}
