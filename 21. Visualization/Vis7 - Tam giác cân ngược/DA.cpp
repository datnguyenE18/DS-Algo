#include <iostream>
using namespace std;

void doPrint ( char c, int num ) {
	for ( int j = 1; j <= num; j++ ) cout << c;
}

int main () {
	int high; cin >> high;
	int space = 0,
		ast = high * 2 - 1;
	for ( int i = high; i >= 1; i-- ) {
		doPrint ( ' ', space );
		doPrint ( '*', ast );
		cout << "\n";
		space++;
		ast -= 2;
	}
	system ( "pause" );
}


