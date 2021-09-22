#include<bits/stdc++.h>
using namespace std;

int a[200],n;

void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}

void sxchen(int a[], int n)
{
	a[-1]=-1;
	for (int i=0;i<n ;i++)
	{
		if (a[i-1]>a[i])
		{
			swap(a[i],a[i-1]);
			for (int j=i;j>0;j--)
				if (a[j-1]>a[j]) swap(a[j],a[j-1]);
        }
        cout<<"Buoc "<<i<<": ";
        for (int j=0;j<=i;j++) cout<<a[j]<<" ";
        cout<<"\n";
	}
}

main()
{
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sxchen(a,n);
}
