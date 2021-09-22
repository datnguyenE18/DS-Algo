#include<bits/stdc++.h>
using namespace std;

main()
{
	int t,n,a[100],d;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n;
		d=1;
		for (int j=0;j<n;j++) cin>>a[j];
		for (int j=0;j<=n/2;j++)
		if (a[j]!=a[n-j-1]) d=0;
		if (d==1) cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
	}
}
