#include<bits/stdc++.h>
using namespace std;

main()
{
	vector <int> a;
	int t,x;
	string s;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>s;
		if (s=="PUSH") 
		{
			cin>>x;
			a.push_back(x);
		}
		else if (s=="PRINT")
		{
			if (a.empty()) cout<<"NONE";
			else cout<<a.back();
			cout<<"\n";
		}
		else if (s=="POP")
		{
			if (!a.empty()) a.pop_back();
		}
	}
}
