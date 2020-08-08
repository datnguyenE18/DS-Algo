#include <iostream>
using namespace std;

int main () {
	int high;
	cin >> high;

	for ( int c = 1; c <= high; c++ ) {
		int r = 1;
		if ( c <= high / 2 + 1 ) {
			for ( ; r <= high; r++ ) {
				if ( r == 1 || c == r || c + r == high + 1 || r == high ) cout << "*";
				else cout << " ";
			} cout << "\n";
		} else {
			for ( ; r <= high; r++ ) {
				if ( r == 1 || r == high ) cout << "*";
				else cout << " ";
			} cout << "\n";
		}
	}system ( "pause" );
}