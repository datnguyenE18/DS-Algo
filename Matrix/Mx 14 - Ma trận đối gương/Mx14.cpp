#include<bits/stdc++.h>
using namespace std;

int t, n, x[111][111];

void input () {
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			cin >> x[i][j];
}

bool compare ( int m, int be, int af ) {
	for ( int i = 0; i < n / 2; i++ ) {
		if ( x[m][be - i] == x[m][af + i] ) continue;
		return false;
	} return true;
}

void solve ( int be, int af ) {
	for ( int i = 0; i < n; i++ ) {
		if ( compare ( i, be, af ) ) continue;
		else {
			cout << 0 << endl;
			return;
		}
	} cout << 1 << endl;
}

int main () {
	cin >> t;
	while ( t-- ) {
		cin >> n;
		input ();
		if ( n % 2 == 0 ) solve ( ( n / 2 ) - 1, n / 2 );
		else solve ( n / 2 - 1, n / 2 + 1 );
	} system ( "pause" );
}