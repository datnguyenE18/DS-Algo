#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void calc(ll x, ll y, ll p) {
	ll res = 1;
	for ( ll i = 1; i <= y; i++ )
		res = ( res * x ) % p;
	cout << res << endl;
}

int main() {
	int t; cin >> t;
	ll x, y, p;
	while ( t-- ) {
		cin >> x >> y >> p;
		calc(x, y, p);
	}
}