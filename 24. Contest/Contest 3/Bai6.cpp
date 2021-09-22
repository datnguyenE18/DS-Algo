#include<bits/stdc++.h>
using namespace std;

int n,a[100];

void solve()
{
	for (int i=0;i<n;i++) cin>>a[i];
	bool ok=true;
	int t=a[0]+a[n-1];
	for (int i=0;i<=n/2;i++)
		if ((a[i]+a[n-i-1])!=t) 
		{
			ok=false;
			break;
		}
	if (ok) cout<<"YES"<<"\n";
	else cout<<"NO"<<"\n";
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
