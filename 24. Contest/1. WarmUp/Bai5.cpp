#include<bits/stdc++.h>
using namespace std; 

main()
{
	string s;
	getline(cin,s);
	if ((s[0]-'0')+(s[4]-'0')==(s[8]-'0')) 
		cout<<"YES";
	else cout<<"NO";
}
