#include<bits/stdc++.h>
using namespace std;

int n,k,a[20];

void check()
{
	int d=0;
	for (int i=1;i<=n;i++)
		if (a[i]==1) d++;
	if (d==k)
	{
		for (int i=1;i<=n;i++) cout<<a[i];
		cout<<"\n";
	}
}

void sinhnp(int x)
{
	for (int i=0;i<=1;i++)
	{
		a[x]=i;
		if (x==n) check();
		else sinhnp(x+1);
	}
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n>>k;
		sinhnp(1);
	}
}
