#include<bits/stdc++.h>
using namespace std;

struct ptu
{
	int b;
	int e;
};

int n,s;
ptu a[1001];

bool cmp(ptu m,ptu n)
{
	return m.b<n.b;
}

void solve()
{
	for (int i=0;i<n;i++)
	{
		cin>>a[i].b;
		a[i].e=i;
	}
	sort(a,a+n,cmp);
	s=0;
	for (int i=0;i<n;i++)
		if (a[i].e!=i) s++;
	cout<<s/2<<"\n";
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
