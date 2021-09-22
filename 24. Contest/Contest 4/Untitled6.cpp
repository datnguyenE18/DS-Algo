#include<bits/stdc++.h>
using namespace std;

struct matran
{
	int n;
	int m[10][10];
}

matran operator *(matran a,matran B)
{
	int i,j,k,n=a.n;
	matran c; c.n=n;
	for (int 0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			c.m[i][j]=0;
			for (k=0;k<n;k++)
				c.m[i][j]=(c.m[i][j]+a.
		}
	}
		
}
main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		matran a;
		a.n=2; a.m[0][0]=1; a.
	}
}
