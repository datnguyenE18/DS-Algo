#include<bits/stdc++.h>
using namespace std;

int a[200],n;

void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}

void sxdctt(int a[],int n)
{
	for (int i=0;i<n-1;i++)
	{
		for (int j=i+1;j<n;j++)
			if (a[j]<a[i]) swap(a[j],a[i]);
		cout<<"Buoc "<<i+1<<": ";
		for (int j=0;j<n;j++) cout<<a[j]<<" ";
		cout<<"\n";
	}
}

main()
{
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sxdctt(a,n);
}
