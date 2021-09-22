#include<bits/stdc++.h>
using namespace std;

int n,a[100001],d;
bool b[100001];

void solve()
{
	memset(b,false,sizeof(b));
	d=0;
	for (int i=0;i<n;i++) 
	{
		cin>>a[i];
		b[a[i]]=true;
	}
	sort(a,a+n);
	for (int i=a[0];i<=a[n-1];i++)
		if (!b[i]) d++;
	cout<<d<<"\n";
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
