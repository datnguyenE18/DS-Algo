#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll;

bool isPerfect(ll n) {
	ll sum = 0;
	for ( ll i = 1; i <= n / 2; i++ )
		if ( n % i == 0 )
			sum += i;

	if ( sum == n ) return true;
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