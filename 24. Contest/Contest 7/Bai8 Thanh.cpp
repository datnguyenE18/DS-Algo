#include <bits/stdc++.h>
using namespace std;
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
typedef long long int ll;
const long long mod = 1e9 + 7;
main()
{
	IOS()
	int T; cin>>T;
	while(T--){
		string s; cin>>s;
		stack <int> st;
		for(int i = 0 ; i < s.size() ; i++){
			if(s[i]=='(') st.push(i);
			else if(s[i]==')'){
				//if(st.size()>0){
					int top = st.top(); st.pop();
					if(top==0) continue;
					if(s[top-1]=='+') continue;
					if(s[top-1]=='-'){
						for(int j = top; j < i ; j++){
							if(s[j]=='+') s[j]='-';
							else if(s[j]=='-') s[j]='+';
						}
					}
				}
			//}
		}
		for(int i = 0 ; i < s.size() ; i++){
			if(s[i]!='(' && s[i] != ')')
				cout<<s[i];
		}
		cout<<"\n";
	}
}
// hii

