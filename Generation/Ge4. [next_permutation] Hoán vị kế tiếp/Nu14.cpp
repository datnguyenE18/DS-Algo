#include <bits\stdc++.h>
using namespace std;

void input ( int k, int x[] ) {
	for ( int i = 0; i < k; i++ ) cin >> x[i];
}

void output ( int k, int x[] ) {
	for ( int i = 0; i < k; i++ ) cout << x[i] << " ";
	cout << endl;
}

int main () {
	int k, t; cin >> t;
	while ( t-- ) {
		cin >> k;
		int x[k];
		input ( k, x );
		next_permutation ( x, x + k );
		output ( k, x );
	} return 0;
}