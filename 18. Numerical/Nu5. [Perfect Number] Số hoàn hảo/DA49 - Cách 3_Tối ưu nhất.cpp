#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll t, n;

bool isPrime(ll n) {
	for ( ll i = 2; i * i <= n; i++ )
		if ( n % i == 0 ) return false;
	return n > 1;
}

ll pw(ll n, ll x) {
	ll res = 1;
	for ( ll i = 0; i < x; i++ )
		res *= n;
	return res;
}

int main() {
	cin >> t;
	while ( t-- ) {
		cin >> n;
		if ( n % 2 != 0 ) cout << 0 << endl;
		else {
			if ( n == 6 ) cout << 1 << endl;
			else {
				ll ans = 0;
				for ( ll i = 3; pw(2, i - 1) * ( pw(2, i) - 1 ) <= n; i += 2 ) {
					if ( pw(2, i - 1) * ( pw(2, i) - 1 ) == n && isPrime(i) == 1 && isPrime(pw(2, i) - 1) == 1 ) {
						ans = 1;
						break;
					}
				}
				cout << ans << endl;
			}
		}
	}
}