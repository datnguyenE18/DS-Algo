#include<bits/stdc++.h>
using namespace std;

int t[10]={1,2,5,10,20,50,100,200,500,1000};

void doitien(int n)
{
	int i=9, d=0;
	while (n>0)
	{
		while(n>=t[i])
		{
			n=n-t[i];
			d++;
		}
		i--;
	}
	cout<<d<<"\n";
}

main()
{
	int t,n;
	cin>>t;
	for (int i=1;i<=t;i++)
	{ 
		cin>>n;
		doitien(n);
	}
}
