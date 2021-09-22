#include<bits/stdc++.h> 
using namespace std;

int a[2000];
bool b[2000];
 
void xuli(int n, int k) 
{
	int d=0; 
	memset(b,sizeof(b),false);
	for (int i=0;i<n;i++) 
	{
		cin>>a[i];
		b[a[i]]=true;
	}
	for (int i=0;i<n-1;i++) 
		for (int j=i+1;j<n;j++)
		{
			if (a[i]+a[j]==k) d++;
		}
	cout<<d<<"\n"; 	
}

main()
{
	int t,n,k; 
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n>>k;
		xuli(n,k); 
	} 
}


