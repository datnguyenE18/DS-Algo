#include <bits/stdc++.h> 
typedef long long int ll;
using namespace std;
void Solution ( ll n ) {
	ll max = 0;
	while ( n % 2 == 0 ) {
		n = n / 2;
		if ( max < 2 ) max = 2;
	}

	for ( ll i = 3; i <= sqrt ( n ); i = i + 2 ) {
		while ( n % i == 0 ) {
			n /= i;
			if ( max < i ) max = i;
		}
	}

	if ( max < n ) max = n;
	cout << max << endl;
}

int main () {
	ll T, n; cin >> T;
	while ( T-- ) {
		cin >> n; Solution ( n );
	}
	system ( "pause" );
	return 0;
}
