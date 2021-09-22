#include<bits/stdc++.h>
using namespace std;

int a[1000];

void swap(int &a,int &b)
{
	int t;
	t=a;
	a=b;
	b=t;
}

void hvike(int a[],int n)
{
	int i=n-1;
	while(i>0 && a[i]>a[i+1]) i--;
	if (i==0)
	{
		for (int j=1;j<=n;j++) cout<<j<<" ";
		return;
	}
	int k=n;
	while(a[k]<a[i]) k--;
	swap(a[i],a[k]);
	int l=i+1; int r=n;
	while(l<r)
	{
		swap(a[l],a[r]);
		l++; r--;
	}
	for (int j=1;j<=n;j++) cout<<a[j]<<" ";	
}
main()
{
	int t,n;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n;
		for (int j=1;j<=n;j++) cin>>a[j];
		hvike(a,n);
		cout<<"\n";
	}
}
