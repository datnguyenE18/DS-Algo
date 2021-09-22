#include <bits/stdc++.h>
using namespace std;
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
typedef long long int ll;
const long long mod = 1e9 + 7;
int priority(char c){
	if(c=='^') return 4;
	if(c=='*' || c=='/') return 3;
	if(c=='+' || c=='-') return 2;
	return 1;
}
main()
{
	IOS()
	int T; cin>>T;
	while(T--){
		string s; cin>>s;
		string res="";
		stack <char> st;
		for(int i = 0 ; i < s.size() ; i++){
			if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z') res+=s[i];
			else if(s[i]=='(') st.push(s[i]);
			else if(s[i]=='+' || s[i]=='/' || s[i]=='*' || s[i]=='-' || s[i]=='^'){
				while(st.size()>0 && priority(st.top()) >= priority(s[i])){
					res += st.top();
					st.pop();
				}
				st.push(s[i]);
			}
			else if(s[i]==')'){
				while(st.size()>0 && st.top()!='('){
					res += st.top();
					st.pop();
				}
				st.pop();
			}
		}
		while(st.size()>0){
			if(st.top()!='(') res += st.top();
			st.pop();
		}
		cout<<res<<"\n";
	}
}
// hii

