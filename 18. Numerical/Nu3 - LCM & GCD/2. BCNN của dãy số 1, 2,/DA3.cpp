#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll GCD(ll a, ll b) {
	if ( a == 0 ) return b;
	return GCD(b % a, a);
}

int main() {
	ll n;
	int t; cin >> t;
	while ( t-- ) {
		cin >> n;
		ll LCM = 1;
		for ( int i = 1; i <= n; i++ )
			LCM = ( LCM * i ) / GCD(LCM, i);
		cout << LCM << endl;
	}
}