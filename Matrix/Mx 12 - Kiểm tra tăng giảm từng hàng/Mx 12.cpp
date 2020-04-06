#include<bits/stdc++.h>
using namespace std;

int t, n, m, temp, x[111][111];

void input () {
	cin >> n >> m;
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < m; j++ ) {
			cin >> x[i][j];
		}
	}
}

bool check ( int c ) {
	for ( int i = m - 1; i >= 3; i-- ) {
		if ( x[c][i] < x[c][i - 1] && x[c][i - 1] < x[c][i - 2] && x[c][i - 2] < x[c][i - 3] ) return true;
	} return false;
}

int main () {
	cin >> t;
	while ( t-- ) {
		temp = 0;
		input ();
		for ( int i = 0; i < n; i++ ) {
			if ( check ( i ) ) {
				temp = i + 1;
				cout << temp << " ";
				continue;
			}
		}
		if ( temp == 0 ) cout << 0;
		cout << "\n";
	} system ( "pause" );
}