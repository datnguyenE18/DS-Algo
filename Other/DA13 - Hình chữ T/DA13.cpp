#include <iostream>
using namespace std;

void doPrint ( char c, int num ) {
	for ( int j = 1; j <= num; j++ ) cout << c;
}

int main () {
	int high, large;
	cin >> high >> large;

	if ( large % 2 == 0 ) {
		for ( int i = 1; i <= high; i++ ) {
			if ( i == 1 || i == 2 ) {
				doPrint ( '*', large );
				cout << "\n";
			} else {
				doPrint ( ' ', large / 2 - 1 );
				doPrint ( '*', 2 );
				cout << "\n";
			}
		}
	} else {
		for ( int i = 1; i <= high; i++ ) {
			if ( i == 1 ) {
				doPrint ( '*', large );
				cout << "\n";
			} else {
				doPrint ( ' ', large / 2 );
				doPrint ( '*', 1 );
				cout << "\n";
			}
		}
	} system ( "pause" );
}


