#include<iostream>
using namespace std;

int main () {
	int column; cin >> column;

	for ( int row = 1; row <= column; row++ ) {
		for ( int i = 1; i <= column - row; i++ ) cout << " ";
		for ( int i = 1; i <= 2 * row - 1; i++ ) cout << "*";
		cout << "\n";
	} system ( "pause" );
}