#include <bits/stdc++.h> 
using namespace std;

void Solution ( int n ) {
	vector <int> mark ( n + 1, true );

	for ( int i = 2; i*i <= n; i++ ) {
		if ( mark[i] ) {
			for ( int j = i*i; j <= n; j += i )
				mark[j] = false;
		}
	}

	for ( int i = 2; i <= n; i++ ) {
		if ( mark[i] ) cout << i << " ";
	} cout << endl;
}

int main () {
	int T, n; cin >> T;
	while ( T-- ) {
		cin >> n;
		Solution ( n );
	}
}
