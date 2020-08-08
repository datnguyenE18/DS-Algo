#include <bits/stdc++.h>
using namespace std;

void k1 ( int x ) {
	int n, i, j, a;
	n = 2 * x - 1;
	a = x - 1;
	for ( i = 1; i <= n; i++ ) {
		if ( i % 2 != 0 ) {
			for ( j = 1; j <= a; j++ )
				cout << " ";

			if ( i == 1 || i == n )
			for ( j = 1; j <= i; j++ )
				cout << "*";
			else {
				for ( j = 1; j <= i; j++ )
				if ( j == 1 || j == i )
					cout << "*";
				else
					cout << " ";
			}
			cout << "\n";
			a--;
		} else {
			cout << "\n";
		}
	}
}
void k2 ( int x ) {
	int n, i, j, a;
	n = x;
	for ( i = 1; i <= n; i++ ) {
		if ( i == 1 || i == n ) {
			for ( j = 1; j <= i; j++ )
				cout << "*";

		} else
		for ( j = 1; j <= i; j++ )
		if ( j == 1 || j == i )
			cout << "*";
		else
			cout << " ";

		cout << "\n\n";
	}
}
int main () {
	int h, k;
	cin >> h >> k;
	if ( k == 1 )
		k1 ( h );
	if ( k == 2 )
		k2 ( h );
	else
		return 0;
}

