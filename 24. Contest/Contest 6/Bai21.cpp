#include<bits/stdc++.h>
using namespace std;

int n,a[10001],b[100001];

bool cmp(int m,int n)
{
	if (b[m]==b[n]) return m<n;
	else return b[m]>b[n];
}

void solve()
{
	memset(b,0,sizeof(b));
	for (int i=0;i<n;i++) 
	{
		cin>>a[i];
		b[a[i]]++;
	}
	sort(a,a+n,cmp);
	for (int i=0;i<n;i++) cout<<a[i]<<" ";
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
