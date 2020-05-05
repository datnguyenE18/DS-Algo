#include <bits/stdc++.h>
using namespace std;

void input ( int x[], int k ) {
	for ( int i = 0; i < k; i++ ) cin >> x[i];
}

void printf ( int x[], int k ) {
	for ( int i = 0; i < k; i++ ) cout << x[i] << " ";
	cout << endl;
}

void orig_config ( int x[], int k ) {
	for ( int i = 1; i <= k; i++ ) cout << i << " ";
	cout << endl;
}

void solve ( int x[], int n, int k ) {
	int mark = 0;
	for ( int i = k - 1; i >= 0; i-- ) {
		if ( x[i] <= n - k + i ) {
			mark = ++x[i];
			for ( int j = i + 1; j < k; j++ ) x[j] = mark++;
			printf ( x, k );
			return;
		}
	} orig_config ( x, k );
}


int main () {
	int n, k, t; cin >> t;
	while ( t-- ) {
		cin >> n >> k;
		int x[k];
		input ( x, k );
		solve ( x, n, k );
	} return 0;
}
