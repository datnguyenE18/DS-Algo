#include<bits/stdc++.h>
using namespace std;

int a[1000];

void tohopke(int n,int k)
{
	int i=k;
	while(i>0 && a[i]==n-k+i) i--;
	if (i>0)
	{
		a[i]++;
		for (int j=i+1;j<=k;j++) a[j]=a[i]+j-i;
	}
	if (i==0) 
		for (int j=1;j<=k;j++) a[j]=j;
	for (int j=1;j<=k;j++) cout<<a[j]<<" ";
	cout<<"\n";
}

main()
{
	int t,n,k;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n>>k;
		for (int i=1;i<=k;i++) cin>>a[i];
		tohopke(n,k);
	}
}
