#include<bits/stdc++.h>
using namespace std;

int id,ok,a[100];
string s;

void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}

void hvike()
{
	int i=s.length()-2;
	while (i>=0 && a[i]>=a[i+1]) i--;
	if (i<=-1) ok=0;
	int k=s.length()-1;
	while (k>=0 && a[k]<=a[i]) k--;
	swap(a[k],a[i]);
	int l=i+1, r=s.length()-1;
	while(l<r) 
	{
		swap(a[l],a[r]);
		l++;
		r--;
	}
}

void solve()
{
	for (int i=0;i<s.length();i++)
		a[i]=s[i]-'0';
	ok=1;
	hvike();
	if (ok==0) cout<<id<<" BIGGEST"<<"\n";
	else
	{
		cout<<id<<" ";
		for (int i=0;i<s.length();i++) 
			cout<<a[i];
		cout<<"\n";
	}
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>id>>s;
		solve();
	}
}
