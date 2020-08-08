#include <iostream>
using namespace std;

int main () {
	int high;
	cin >> high;

	for ( int c = 1; c <= high; c++ ) {
		for ( int r = 1; r <= high; r++ ) {
			if ( r > c && r <= high - c || r > high - c + 1 && r < c ) cout << " ";
			else cout << "*";
		} cout << "\n";
	}system ( "pause" );
}