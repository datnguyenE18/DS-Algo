#include<bits/stdc++.h>
using namespace std;

long long ucln(long long a,long long b)
{
	long long t;
	while (b!=0)
	{
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}

long long bcnn(long long a,long long b)
{
	long long t=a*b/ucln(a,b);
	return t;
}

main()
{
	long long t,a,b;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>a>>b;
		cout<<ucln(a,b)<<" "<<bcnn(a,b)<<"\n";
	}
}
