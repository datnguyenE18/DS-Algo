#include <bits/stdc++.h> 
using namespace std;

void Solution ( int m, int n ) {
	vector <int> mark ( n + 1, true );
	mark[0] = false;
	mark[1] = false;
	for ( int i = 2; i <= sqrt ( n ); i++ ) {
		if ( mark[i] ) {
			for ( int j = i*i; j <= n; j += i )
				mark[j] = false;
		}
	}

	for ( int i = m; i <= n; i++ ) {
		if ( mark[i] ) cout << i << " ";
	} cout << endl;
}

int main () {
	int T, m, n; cin >> T;
	while ( T-- ) {
		cin >> m >> n;
		Solution ( m, n );
	}
}
