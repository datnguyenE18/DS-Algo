#include <iostream>
using namespace std;

int main () {
	int high; cin >> high;

	for ( int r = 1; r <= high; r++ ) {
		for ( int c = 1; c <= high; c++ ) {
			if ( r == c || r + c == high + 1 ) cout << "*";
			else cout << " ";
		} cout << "\n";
	} system ( "pause" );
}

