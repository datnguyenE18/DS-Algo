#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll;

bool isPerfect(ll n) {
	ll sum = 1;
	for ( ll i = 2; i <= sqrt(n); i++ )
		if ( n % i == 0 ) {
			if ( i != sqrt(n) )
				sum = sum + i + n / i;
			else sum = sum + i;
		}

	if ( sum == n && n != 1 ) return true;
	return false;
}

int main() {
	int T; cin >> T;
	ll n;
	while ( T-- ) {
		cin >> n;
		if ( isPerfect(n) ) cout << 1 << endl;
		else cout << 0 << endl;
	}
}