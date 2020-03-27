#include<iostream>
using namespace std;

int main () {
	int row = 1, column;
	cin >> column;
	for ( ; row <= column; row++ ) {
		int ast = 2 * row - 1; //ast = asterisk
		for ( int i = 1; i <= column - ast / 2 - 1; i++ ) cout << " ";
		for ( int i = 1; i <= ast; i++ ) cout << "*";
		cout << "\n";
	} system ( "pause" );
}
