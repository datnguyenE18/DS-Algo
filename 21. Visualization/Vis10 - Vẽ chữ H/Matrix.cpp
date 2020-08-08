#include <iostream>
using namespace std;

int main () {
	int high, width;
	cin >> high >> width;

	for ( int r = 1; r <= high; r++ ) {
		for ( int c = 1; c <= width; c++ ) {
			if ( c == 1 || c == width ) cout << "*";
			else if ( r == high / 2 + 1 ) cout << "*";
			else cout << " ";
		} cout << "\n";
	} system ( "pause" );
}

