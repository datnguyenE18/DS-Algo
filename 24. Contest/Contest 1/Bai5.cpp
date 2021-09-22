#include<bits/stdc++.h>
using namespace std;

int a[20],n,k;

/*void tohop(int n,int k)
{
	for (int i=1;i<=k;i++) a[i]=i;
	while(1)
	{
		for (int j=1;j<=k;j++) cout<<a[j];
		cout<<" ";	
		int i=k;
		while(i>0 && a[i]==n-k+i) i--;
		if (i==0) return;
		a[i]++;
		for (int j=i+1;j<=k;j++) a[j]=a[i]+j-i;
	}
}*/

void tryy(int x)
{
	for (int i=a[x-1]+1;i<=n-k+x;i++)
	{
		a[x]=i;
		if (x==k) 
		{
			for (int j=1;j<=k;j++)
				cout<<a[j];
			cout<<" ";
		}
		else tryy(x+1);
	}
}
main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n>>k;
		//tohop(n,k);
		tryy(1);
		cout<<"\n";
	}
}
