#include <iostream>
using namespace std;

void doPrint ( char, int );
void Odd ( int );
void Even ( int );

int main () {
	int high; cin >> high;
	if ( high % 2 != 0 ) Odd ( high );
	else Even ( high );
	system ( "pause" );
}

void doPrint ( char c, int num ) {
	for ( int j = 1; j <= num; j++ ) cout << c;
}

void Odd ( int high ) {
	int spaceOut = 0,
		spaceIn = high - 2;
	//Top:
	int i = 1;
	for ( ; i <= high / 2 + 1; i++ ) {
		doPrint ( ' ', spaceOut );
		cout << "*";
		if ( spaceIn > 0 ) {
			doPrint ( ' ', spaceIn );
			cout << "*" << endl;
		}
		spaceOut++;
		spaceIn -= 2;
	}

	//Tail:
	cout << "\n";
	spaceOut -= 2;
	spaceIn = 1;
	for ( ; i <= high; i++ ) {
		doPrint ( ' ', spaceOut );
		cout << "*";
		doPrint ( ' ', spaceIn );
		cout << "*" << endl;

		spaceOut--;
		spaceIn += 2;
	}
}

void Even ( int high ) {
	int spaceOut = 0,
		spaceIn = high - 2;
	//Top:
	int i = 1;
	for ( ; i <= high / 2; i++ ) {
		doPrint ( ' ', spaceOut );
		cout << "*";
		doPrint ( ' ', spaceIn );
		cout << "*" << endl;

		spaceOut++;
		spaceIn -= 2;
	}

	//Tail:
	spaceOut --;
	spaceIn = 0;
	for ( ; i <= high; i++ ) {
		doPrint ( ' ', spaceOut );
		cout << "*";
		doPrint ( ' ', spaceIn );
		cout << "*" << endl;

		spaceOut--;
		spaceIn += 2;
	}
}
