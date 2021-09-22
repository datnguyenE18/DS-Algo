#include<bits/stdc++.h>
using namespace std;

long long f[81], a[9][9];

void fibo(int n)
{
	f[0]=1; f[1]=1;
	for (int i=2;i<n;i++) f[i]=f[i-1]+f[i-2];
}

void print(int n)
{
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++) cout<<a[i][j]<<" ";
		cout<<"\n";
	}
}

void matrixfibo(int n)
{
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++) a[i][j]=0;
	int d=0, x=0, y=n;
	while (d<n*n)
	{
		for (int i=x;i<y;i++)
		{
			a[x][i]=f[d];
			d++;
		}
		for (int i=x+1;i<y;i++)
		{
			a[i][y-1]=f[d];
			d++;
		}
		for (int i=y-2;i>=x;i--)
		{
			a[y-1][i]=f[d];
			d++;
		}
		for (int i=y-2;i>x;i--)
		{
			a[i][x]=f[d];
			d++;
		}
		x++; y--;
	}
	print(n);
}
main()
{
	int t,n;
	fibo(81);
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n;
		cout<<"Test "<<i<<":"<<"\n";
		matrixfibo(n);
	}
}
