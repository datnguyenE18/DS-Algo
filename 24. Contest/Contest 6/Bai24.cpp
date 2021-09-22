#include<bits/stdc++.h>
using namespace std;

int a[10000000],n,x;

int tknp(int l,int r,int x)
{
	while (l<=r)
	{
		int m=(l+r)/2;
		if (a[m]<x) l=m+1;
		else
		if (a[m]>x) r=m-1;
		else
		if (a[m]==x) return m;
	}
	return -1;
}

void solve()
{
	int k=0;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<n;i++) 
		if (a[i]>a[i+1]) 
		{
			k=i;
			break;
		}
	if (tknp(0,k,x)!=-1) cout<<tknp(0,k,x)<<"\n";
	else 
	if (tknp(k+1,n,x)!=-1) cout<<tknp(k,n-1,x)<<"\n";
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n>>x;
		solve();
	}
}
