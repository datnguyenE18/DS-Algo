#include<bits/stdc++.h>
using namespace std;

struct work
{
	int s;
	int e;
};

int n,d;
work a[1001];

bool cmp(work a,work b)
{
	return a.e<b.e;
}

void solve()
{
	for (int i=0;i<n;i++) cin>>a[i].s;
	for (int i=0;i<n;i++) cin>>a[i].e;
	sort(a,a+n,cmp);
	d=1;
	int m=0;
	for (int i=1;i<n;i++)
		if (a[i].s>=a[m].e)
		{
			m=i;
			d++;
		}
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
