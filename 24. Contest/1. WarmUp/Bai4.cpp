#include<bits/stdc++.h>
using namespace std;

void ptnt(int n)
{
	int d=0;
	while(n%2==0)
	{
		d++;
		n=n/2;
	}
	if (d!=0) 
	{
		cout<<"2("<<d<<") ";
		d=0;
	}
	for (int i=3;i<=sqrt(n);i+=2)
	{
		while(n%i==0)
		{
			d++;
			n=n/i;
		}	
		if (d!=0)
		{
			cout<<i<<"("<<d<<") ";
			d=0;
		}
	}
	if (n>2) cout<<n<<"(1) "<<"\n";
	else cout<<"\n";
}

main()
{
	int t,n;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n;
		cout<<"Test "<<i<<": ";
		ptnt(n);
	}
}
