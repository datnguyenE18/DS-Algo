#include<bits/stdc++.h>
using namespace std;

int a[11][11],hv[11],k,n,ok[11],c;
vector <int> *r;

void check()
{
	int d=0;
	for (int i=1;i<=n;i++)
		d=d+a[i][hv[i]];
	if (d==k)
	{
		c++;
		for (int i=1;i<=n;i++) r[c].push_back(hv[i]);
	}		
}

void hvi(int x)
{
	for (int i=1;i<=n;i++)
	{
		if (ok[i]==0)
		{
			ok[i]=1;
			hv[x]=i;
			if (x==n) check();
			else hvi(x+1);
			ok[i]=0;
		}
	}
}

void solve()
{
	c=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) cin>>a[i][j];
	r=new vector <int> [100];
	memset(ok,0,sizeof(ok));
	hvi(1);
	cout<<c<<"\n";
	for (int i=1;i<=c;i++)
	{
		for (int j=0;j<r[i].size();j++)
			cout<<r[i][j]<<" ";
		cout<<"\n";
	}
}

main()
{
	cin>>n>>k;
	solve();
}
