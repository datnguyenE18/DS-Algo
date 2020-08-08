#include <iostream>
using namespace std;

void doPrint ( char c, int num ) {
	for ( int j = 1; j <= num; j++ ) cout << c;
}

void doPrintNum ( int c, int num ) {
	for ( int j = 1; j <= num; j++ ) cout << c;
}

int main () {
	int high; cin >> high;
	int space = 0,
		ast = high * 2 - 1,
		num = 1;

	for ( int i = 1; i <= high; i++ ) {
		doPrint ( ' ', space );
		doPrintNum ( num, ast );
		cout << "\n";
		space++;
		ast -= 2;
		num += 2;
	} system ( "pause" );
}


