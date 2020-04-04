#include<bits/stdc++.h>
using namespace std;

int n, total;
int x[111][111];

void input () {
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			cin >> x[i][j];
}

void t_row () {
	for ( int i = 0; i < n; i++ ) {
		total = 0;
		for ( int j = 0; j < n; j++ ) {
			total += x[i][j];
		} cout << total << endl;
	}
}

int main () {
	cin >> n;
	input ();
	t_row ();
	system ( "pause" );
}