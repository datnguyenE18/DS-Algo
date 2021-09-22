#include<bits/stdc++.h>
using namespace std;

int convert(char a)
{
	return a-'0';
}

int number(string s)
{
	int n=0;
	for (int i=0;i<s.length();i++)
		n=n*10+convert(s[i]);
	return n;	
}

void summin(string a, string b)
{
	for (int i=0;i<a.length();i++)
		if (a[i]=='6') a[i]='5';
	for (int i=0;i<b.length();i++)
		if (b[i]=='6') b[i]='5';
	int min=number(a)+number(b);
	cout<<min<<" ";
}

void summax(string a, string b)
{
	for (int i=0;i<a.length();i++)
		if (a[i]=='5') a[i]='6';
	for (int i=0;i<b.length();i++)
		if (b[i]=='5') b[i]='6';
	int max=number(a)+number(b);
	cout<<max<<"\n";
}

main()
{
	string a,b;
	cin>>a>>b;
	summin(a,b);
	summax(a,b);
}
