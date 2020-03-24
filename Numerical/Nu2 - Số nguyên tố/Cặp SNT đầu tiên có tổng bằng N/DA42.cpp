#include<bits/stdc++.h>
using namespace std;

void Eratosthenes ( int n ) {
	vector <int> mark ( n + 1, true );
	mark[0] == false;
	mark[1] == false;

	for ( int i = 2; i <= sqrt ( n ); i++ ) {
		if ( mark[i] ) {
			for ( int j = i*i; j <= n; j += i )
				mark[j] = false;
		}
	}
	for ( int i = 2; i <= n / 2; i++ ) {
		int m = n - i;
		if ( mark[m] == true && mark[i] == true ) {
			cout << i << " " << m << endl;
			break;
		}
	}
}

int main () {
	int n, T; cin >> T;
	while ( T-- ) {
		cin >> n;
		Eratosthenes ( n );
	} system ( "pause" );
}