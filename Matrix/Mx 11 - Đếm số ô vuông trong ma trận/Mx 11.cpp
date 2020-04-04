#include<bits/stdc++.h>
using namespace std;

int n_col, n_row, sz, x[111][111];

void input () {
	cin >> n_row >> n_col >> sz;

	for ( int i = 0; i < n_row; i++ )
		for ( int j = 0; j < n_col; j++ )
			cin >> x[i][j];
}

int isHV ( int row, int col, int sz ) {
	for ( int i = row; i < row + sz; i++ ) 
		for ( int j = col; j < col + sz; j++ ) 
			if ( x[i][j] == 0 )
				return 0;
	return 1;
}

void solve () {
	int dem = 0;
	for ( int i = 0; i <= n_row - sz; i++ ) 
		for ( int j = 0; j <= n_col - sz; j++ ) 
			if ( isHV ( i, j, sz ) == 1 )
				dem++;
	cout << dem << endl;
}

int main () {
	int t; cin >> t;

	while ( t-- ) {
		input ();
		solve ();
	} system ( "pause" );
}