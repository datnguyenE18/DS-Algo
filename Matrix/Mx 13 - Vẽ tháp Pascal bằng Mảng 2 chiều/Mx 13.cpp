#include<bits/stdc++.h>
using namespace std;

int x[111][111], n, t;

void display () {
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < 2 * n - 1; j++ ) {
			cout << x[i][j] << "";
		} cout << "\n";
	} cout << "\n";
}

void solve () {
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < 2 * n - 1; j++ ) {
			if ( j <= i ) x[i][j] = j + 1;
			else if ( j > i && j <= 2 * i ) x[i][j] = 2 * i - j + 1;
			else x[i][j] = 0;
		}
	}
}

int main () {
	cin >> t;
	while ( t-- ) {
		cin >> n;
		solve ();
		display ();
	} system ( "pause" );
}
