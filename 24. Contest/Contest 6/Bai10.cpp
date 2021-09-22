#include<bits/stdc++.h>
using namespace std;

long long x,n;
bool a[10];

void ptich(long long x)
{
	while(x>0)
	{
		if (!a[x%10]) a[x%10]=true;
		x=x/10;
	}
}

void solve()
{
	memset(a,false,sizeof(a));
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		ptich(x);
	}
	for (int i=0;i<=9;i++)
		if (a[i]) cout<<i<<" ";
	cout<<"\n";
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
