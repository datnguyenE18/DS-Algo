#include<bits/stdc++.h>
using namespace std;

int n,k,d,a[50];
bool b[50],ok;

void tohopke()
{
	int i=k;
	while(i>0 && a[i]==n-k+i) i--;
	if (i==0) ok=true;
	a[i]=a[i]+1;
	for (int j=i+1;j<=k;j++) 
		a[j]=a[i]+j-i;
}

void solve()
{
	memset(b,false,sizeof(b));
	ok=false;
	for (int i=1;i<=k;i++)
	{
		cin>>a[i];
		b[a[i]]=true;
	}
	tohopke();
	if (ok) cout<<k<<"\n";
	else
	{
		d=0;
		for (int i=1;i<=k;i++)
			if (!b[a[i]]) d++;
		cout<<d<<"\n";
	}
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n>>k;
		solve();
	}
}
