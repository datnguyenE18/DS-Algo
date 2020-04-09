#include<iostream>
using namespace std;

bool test;

void out ( int n, int a[] ) {
	for ( int i = 1; i <= n; i++ ) cout << a[i];
	cout << " ";
}

void next_permutation ( int n, int a[] ) {
	int i = n - 1;
	while ( i > 0 && a[i] > a[i + 1] ) i--;
	if ( i > 0 ) {
		int j = n;
		while ( a[i] > a[j] ) j--;
		swap ( a[i], a[j] );
		int k = i + 1, h = n;
		while ( k <= h ) {
			swap ( a[k], a[h] );
			k++;
			h--;
		}
	} else test = false;
}

int main () {
	int T; cin >> T;

	while ( T-- ) {
		test = true;
		int n;
		cin >> n;
		int a[n];
		for ( int i = 1; i <= n; i++ ) a[i] = i;

		while ( test ) {
			out ( n, a );
			next_permutation ( n, a );
		} cout << "\n";
	} return 0;
}
