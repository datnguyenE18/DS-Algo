#include<bits/stdc++.h>
using namespace std;

long long a[100000];
int n;

void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}

void bbsort(long long a[],int n)
{
	int d=0;
	bool kt=true;
	for (int i=0;i<n-1;i++)
	{ 
		kt=true;
		for (int j=0;j<n-i-1;j++)
			if (a[j]>a[j+1]) 
			{
				kt=false;
				swap(a[j],a[j+1]);
			}
		if (kt) break;
		cout<<"Buoc "<<i+1<<": ";
		for (int i=0;i<n;i++) cout<<a[i]<<" ";
		cout<<"\n";
	}	
}

main()
{
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	bbsort(a,n);
}
