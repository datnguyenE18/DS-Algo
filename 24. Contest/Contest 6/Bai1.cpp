#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}

void sortctt(int a[],int n,int x)
{
	int i=0;
	while (i<n)
	{
		for (int j=i+1;j<=n;j++)
			if (a[i]>a[j]) swap(a[i],a[j]);
		i++;
	}
}

main()
{
	int t,n,x,a[10000];
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n;
		for (int j=0;j<n;j++) cin>>a[j];
		sortctt(a,n-1,x);
		int l=0; int r=n-1;
		while (l<r)
		{
			cout<<a[r]<<" ";
			cout<<a[l]<<" ";
			l++; r--;
		}
		if (n%2==1) cout<<a[l];
		cout<<"\n";
	}
}
