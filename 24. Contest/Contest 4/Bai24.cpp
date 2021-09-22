#include<bits/stdc++.h>
using namespace std;

int M=123456789;

long long powerM(long long n,long long k)
{
	if (k==0) return 1;
	long long x=powerM(n,k/2);
	if (k%2==0) return x*x%M;
	return n*(x*x%M)%M;
}

main()
{
	long long t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<powerM(2,n-1)<<"\n";
	}
}
