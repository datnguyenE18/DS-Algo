#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//Tìm UCLN theo Euclid
ll GCD ( ll a, ll b ) {
	if ( a == 0 ) return b;
	return GCD ( b % a, a );
}

int main () {
	ll n, test;
	cin >> n;
	while ( n-- ) {
		cin >> test;
		ll result = 1;
		for ( ll i = 2; i <= test; i++ ) {
			result = ( i * result ) / GCD ( i, result );
		}
		cout << result << endl;
	}

	system ( "pause" );
	return 0;
}