#include<bits/stdc++.h>
using namespace std; 

string a,b;
int k;

void solve()
{
	while(a.length()>b.length()) b='0'+b;
	while(b.length()>a.length()) a='0'+a;
	string s="";
	int nho=0;
	for (int i=a.length()-1;i>=0;i--)
	{
		int t=(a[i]-'0')+(b[i]-'0')+nho;
		nho=t/k;
		s=char(t%k+'0')+s;
	}
	if (nho>0) s=char(nho+'0')+s;
	cout<<s<<"\n";
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>k>>a>>b;
		solve();
	}	
}
