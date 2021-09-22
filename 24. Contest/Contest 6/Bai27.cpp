#include<bits/stdc++.h>
using namespace std;

int a[200],n;

void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}

void sxchon(int a[],int n)
{
	int min=0, j=0;
	bool kt=true;
	while (j<n)
	{
		kt=true;
		for (int i=j+1; i<n; i++) 
			if (a[i]<a[min]) 
			{
				kt=false;
				min=i;
			}
		swap(a[min],a[j]);
		j++;
		min=j;
		if (kt) break;
		cout<<"Buoc "<<j<<": ";
		for (int i=0;i<n;i++) cout<<a[i]<<" ";
		cout<<"\n";
	}
}

main()
{
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sxchon(a,n);
}
