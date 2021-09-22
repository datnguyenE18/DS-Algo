#include<bits/stdc++.h>
using namespace std;

int a[100000];

void tknp(int a[],int n,int k)
{
	int l=1, r=n;
	while(l<=r)
	{
		int m=(l+r)/2;
		if (k==a[m])
		{
			cout<<m<<"\n";
			return;
		}
		else if(k>a[m]) l=m+1;
		else r=m-1;
	}
	cout<<"NO"<<"\n";
}

main()
{
	int t,n,k;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n>>k;
		for (int j=1;j<=n;j++) cin>>a[j];
		tknp(a,n,k);
	}
}
