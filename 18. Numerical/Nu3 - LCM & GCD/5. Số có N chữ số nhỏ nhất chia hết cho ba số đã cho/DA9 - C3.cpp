#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll GCD ( ll a, ll b ) {
	if ( a == 0 ) return b;
	return GCD ( b % a, a );
}

ll LCM ( ll a, ll b ) {
	return ( a * b ) / GCD ( a, b );
}

void solve ( ll x, ll y, ll z, int N ) {
	ll temp = LCM ( LCM ( x, y ), z ),
		digit = pow ( 10, N - 1 );
	if ( temp >= pow ( 10, N ) ) cout << -1 << endl;
	else if ( temp >= digit ) cout << temp << endl;
	else if ( digit % temp == 0 ) cout << digit << endl;
	else cout << temp * ( ll ) ( ( digit / temp ) + 1 ) << endl;
}

int main () {
	ll x, y, z;
	int N, t; cin >> t;
	while ( t-- ) {
		cin >> x >> y >> z >> N;
		solve ( x, y, z, N );
	} system ( "pause" );
}