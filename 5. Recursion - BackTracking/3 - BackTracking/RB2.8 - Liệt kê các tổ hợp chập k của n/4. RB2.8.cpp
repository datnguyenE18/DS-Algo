#include<bits/stdc++.h>
using namespace std;
#define MAX 20

int n, k, X[MAX];

void display () {
	for ( int i = 1; i <= k; i++ ) {
		cout << X[i];
	} cout << " ";
}

void Try ( int i ) {
	for ( int j = X[i - 1] + 1; j <= n - k + i; j++ ) {
		X[i] = j;
		if ( i == k ) {
			display ();
		} else Try ( i + 1 );
	}
}

int main () {
	int t; cin >> t;
	while ( t-- ) {
		X[0] = 0;
		cin >> n >> k;
		Try ( 1 );
		cout << "\n";
	} system ( "pause" );
}