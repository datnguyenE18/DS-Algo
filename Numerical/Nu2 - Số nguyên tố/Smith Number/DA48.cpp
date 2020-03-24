#include<bits/stdc++.h>
using namespace std;

int tongChuSo ( int n ) {
	int sum = 0;
	while ( n != 0 ) {
		sum += n % 10;
		n /= 10;
	} return sum;
}

int tongUoc ( int n ) {
	int sum = 0;
	int start = n;

	for ( int i = 2; i <= sqrt ( n ); i++ ) {
		while ( n % i == 0 ) {
			sum += tongChuSo ( i );
			n /= i;
		}
	}
	if ( start == n ) return 0;
	else if ( 2 < n ) sum += tongChuSo ( n );
	return sum;
}

int main () {
	int n, T; cin >> T;
	while ( T-- ) {
		cin >> n;
		if ( tongUoc ( n ) ) {
			if ( tongChuSo ( n ) == tongUoc ( n ) ) {
				cout << "YES" << endl;
				continue;
			}
		} cout << "NO" << endl;
	} system ( "pause" );
}