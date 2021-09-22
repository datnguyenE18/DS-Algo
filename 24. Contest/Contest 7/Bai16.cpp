#include<bits/stdc++.h>
using namespace std;

string s;

void solve()
{
	stack <int> a;
	for (int i=0;i<s.length();i++)
	{
		if (s[i]>='0' && s[i]<='9') a.push(s[i]-'0');
		else
		{
			int x1=a.top();
			a.pop();
			int x2=a.top();
			a.pop();
			switch (s[i])
			{
				case '+': a.push(x2+x1); break;
				case '-': a.push(x2-x1); break;
				case '*': a.push(x2*x1); break;
				case '/': a.push(x2/x1); break;
			}
		}
	}
	cout<<a.top()<<"\n";
}

main()
{
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>s;
		solve();
	}
}
