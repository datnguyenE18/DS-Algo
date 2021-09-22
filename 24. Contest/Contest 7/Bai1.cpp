#include<bits/stdc++.h>
using namespace std;

main()
{
	string s;
	int n;
	vector <int> a;
	while (cin>>s)
	{
		if (s=="push") 
		{
			cin>>n;
			a.push_back(n);
		}
		else if (s=="pop")
		{
			if (a.empty()) cout<<"empty";
			else a.pop_back();
		}
		else if (s=="show")
		{
			if (a.empty()) cout<<"empty";
			for (int i=0;i<a.size();i++) cout<<a[i]<<" ";
			cout<<"\n";
		}
		
	}
}
