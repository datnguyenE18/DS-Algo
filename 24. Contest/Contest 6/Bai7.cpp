#include<bits/stdc++.h>
using namespace std;

long long n,ok,a[1000001],b[1000001];

void solve()
{
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+n+1);
	ok=0;
	int i,j;
	for (i=1;i<=n;i++)
		if (a[i]!=b[i])
		{
			ok=1;
			break;
		}
	for (j=n;j>0;j--)
		if (a[j]!=b[j]) break;
	if (ok==0) cout<<"\n";
	else cout<<i<<" "<<j<<"\n";
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
