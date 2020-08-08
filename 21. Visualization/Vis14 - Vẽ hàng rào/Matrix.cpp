#include <iostream>
using namespace std;

void doPrint ( char c, int num ) {
	for ( int i = 1; i <= num; i++ ) cout << c;
}

int main () {
	int hi, wi, spa;
	cin >> hi >> wi >> spa;

	//Head:
	for ( int row = 1; row < hi; row++ ) {
		for ( int colu = 1; colu <= wi; colu++ ) {
			if ( colu == 1 || ( colu - 1 ) % spa == 0 ) cout << "*";
			else cout << " ";
		} cout << "\n";
	}

	//Tail:
	doPrint ( '*', wi );
	cout << "\n";
	system ( "pause" );
}