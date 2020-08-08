#include<bits/stdc++.h>
using namespace std;

int n;
int x[111][111];

void input () {
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			cin >> x[i][j];
}

void solve () {
	for ( int i = 0; i < n; i++ ) {
		for ( int j = n - 1; j >= 0; j-- ) {
			cout << x[i][j] << " ";
		} cout << endl;
	}
}

int main () {
	cin >> n;
	input ();
	solve ();
	system ( "pause" );
}