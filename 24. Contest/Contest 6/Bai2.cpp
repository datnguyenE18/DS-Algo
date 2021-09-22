#include<bits/stdc++.h>
using namespace std;

struct ptu
{
	int b;
	int e;
};

int n,x;
ptu a[100001];

bool cmp(ptu m,ptu n)
{
	if (abs(x-m.b)==abs(x-n.b)) return m.e<n.e;
	else return abs(x-m.b)<abs(x-n.b);
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n>>x; 
		for (int j=0;j<n;j++) 
		{
			cin>>a[j].b;
			a[j].e=j;
		}
		sort(a,a+n,cmp);
		for (int j=0;j<n;j++) cout<<a[j].b<<" ";
		cout<<"\n";
	}
}
