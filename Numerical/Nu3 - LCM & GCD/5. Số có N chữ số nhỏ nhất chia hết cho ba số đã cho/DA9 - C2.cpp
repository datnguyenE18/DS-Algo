#include <bits/stdc++.h>
using namespace std;

long long gcd ( int a, int b ) {
	if ( b == 0 ) return a;
	else
		return gcd ( b, a%b );
}

int main () {
	int t;
	cin >> t;
	while ( t-- ) {
		long long int a[3], n;
		cin >> a[0] >> a[1] >> a[2] >> n;
		long long int x = pow ( 10, n - 1 );
		long long int k = ( a[0] * a[1] ) / gcd ( a[0], a[1] ), s;
		k = ( a[2] * k ) / gcd ( a[2], k );
		int dig = 0;
		s = k;
		while ( s ) {
			s = s / 10;
			dig++;
		}

		long long int divi = x / k;
		if ( dig > n )
			cout << -1 << endl;
		else if ( x%k == 0 )
			cout << x << endl;
		else {
			cout << ( divi + 1 )*k << endl;
		}
	}

	system ( "pause" );
	return 0;
}