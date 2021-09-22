#include<bits/stdc++.h>
using namespace std;

int a[10000000],n,ok;

void solve()
{
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	ok=0;
	for (int i=1;i<n;i++)
		if (a[i]>a[0])
		{
			ok=1;
			cout<<a[0]<<" "<<a[i]<<"\n";
			break;
		}
	if (ok==0) cout<<"-1"<<"\n";
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
