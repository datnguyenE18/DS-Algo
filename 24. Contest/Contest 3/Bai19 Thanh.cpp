#include <bits/stdc++.h>
#define IOS() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long int ll;
const long long mod = 1e9 + 7;
void fraction(ll t, ll m){
	ll n;
	while(1){
		if(m % t == 0){
			cout<<"1/"<<m/t;
			return;
		}
		else{
			int n = m/t + 1;
			cout<<"1/"<<n<<" + ";
			t = t*n - m;
			m = m*n;
		}
	}
}

main(){
	int T;
	IOS()
	cin>>T;
	while(T--){
		ll P,Q; cin>>P>>Q;
		fraction(P,Q);
		cout<<"\n";
	}
}


