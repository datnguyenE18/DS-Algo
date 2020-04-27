#include<bits/stdc++.h>
using namespace std;

int n, X[20];
bool chuaxet[21];

void display () {
	for ( int vt = 1; vt <= n; vt++ ) {
		cout << X[vt];
	} cout << " ";
}

void qlHoanVi ( int vt ) {
	for ( int gt = 1; gt <= n; gt++ ) {
		if ( chuaxet[gt] ) {
			X[vt] = gt; chuaxet[gt] = false;
			if ( vt == n ) display ();
			else qlHoanVi ( vt + 1 );
			chuaxet[gt] = true;
		}
	}
}

int main () {
	int t; cin >> t;
	while ( t-- ) {
		memset ( chuaxet, true, 21 );
		cin >> n;
		qlHoanVi ( 1 );
		cout << "\n";
	} system ( "pause" );
}