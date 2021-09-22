#include<bits/stdc++.h>
using namespace std;

void solve(string s)
{
	stack <char> a;
	for (int i=0;i<s.length();i++)
		if (s[i]==' ') 
		{
			while (!a.empty()) 
			{
				cout<<a.top();
				a.pop();
			}
			if (s[i+1]!=' ') cout<<" ";
		}
		else a.push(s[i]);
	while (!a.empty()) 
			{
				cout<<a.top();
				a.pop();
			}
	cout<<"\n";
}

main()
{
	int t;
	string s;
	cin>>t;
	cin.ignore();
	for (int i=1;i<=t;i++)
	{
		getline(cin,s);
		if (s.length()!=0) solve(s);
		else t++;
	}
}
