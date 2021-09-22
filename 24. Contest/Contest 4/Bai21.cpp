#include<bits/stdc++.h>
using namespace std;
int M=1e9+7;
long long powerM(int n,int k)
{
	if (k==0) return 1;
	long long x=powerM(n,k/2);
	if (k%2==0) return x*x%M;
	return n*(x*x%M)%M;
}

main()
{
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		cout<<powerM(n,k)<<"\n";
	}
}
