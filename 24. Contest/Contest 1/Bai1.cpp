#include<bits/stdc++.h>
using namespace std; 

void npketiep(string s)
{
	string x=s;
	int i=x.length()-1;
	while(i>=0 && x[i]=='1')
	{
		x[i]='0';
		i--;
	}
	if (i>=0) x[i]='1';
	cout<<x<<"\n";
}

main()
{
	int t;
	string s;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>s;
		npketiep(s);
	}
}
