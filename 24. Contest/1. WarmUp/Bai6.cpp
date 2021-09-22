#include<bits/stdc++.h>
using namespace std;

int a[21][21];

void print(int n)
{
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++) cout<<a[i][j]<<" ";
		cout<<"\n";
	}
}

void xoayoc(int n)
{
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++) a[i][j]=0;
	int x=0, y=n-1;
	int d=n*n;
	while (d>=1)
	{
	for (int i=x;i<=y;i++) 
	{
		a[x][i]=d;
		d--;
	}
	for (int i=x+1;i<=y;i++)
	{
		a[i][y]=d;
		d--;
	}
	for (int i=y-1;i>=x;i--)
	{
		a[y][i]=d;
		d--;
	}
	for (int i=y-1;i>x;i--)
	{
		a[i][x]=d;
		d--;
	}
	x++; y--;
	}
	print(n);
}

main()
{
	int t,n;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n;
		cout<<"Test "<<i<<":"<<"\n";
		xoayoc(n);
	}
}
