#include<bits/stdc++.h>
using namespace std;

int a[11],check[11],n;

/*void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}

void hvi(int n)
{
	for (int i=1;i<=n;i++) a[i]=i;
	while (1)
	{
		for (int i=1;i<=n;i++) cout<<a[i];
		cout<<" ";
		int i=n-1;
		while(i>0 && a[i]>a[i+1]) i--;
		if (i==0) return;
		int k=n;
		while(k>0 && a[k]<a[i]) k--;
		swap(a[k],a[i]);
		int l=i+1; int r=n;
		while(l<r)
		{
			swap(a[l],a[r]);
			l++; r--;
		}
	}
}*/

void tryy(int x)
{
	for (int i=1;i<=n;i++)
	{
		if (check[i]==0) 
		{
			check[i]=1;
			a[x]=i;
			if (x==n)
			{
				for (int j=1;j<=n;j++) cout<<a[j];
				cout<<" ";
			}
			else tryy(x+1);
			check[i]=0;
		}
	}
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n;
		//hvi(n);
		memset(check,0,sizeof(check));
		tryy(1);
		cout<<"\n";
	}
}
