#include<iostream>
using namespace std;

void doPrint ( char c, int amount ) {
	for ( int i = 1; i <= amount; i++ ) cout << c;
}

int main () {
	int column;
	cin >> column;

	int space = column - 1;
	int asterisk = 1;

	for ( int i = 1; i <= column; i++ ) {
		doPrint ( ' ', space );
		doPrint ( '*', asterisk );
		cout << "\n";

		space--;
		asterisk += 2;
	}
	system ( "pause" );
}
