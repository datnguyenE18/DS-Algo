#include<iostream>
using namespace std;

void doPrint ( char c, int amount ) {
	for ( int i = 1; i <= amount; i++ ) cout << c;
}

int main () {
	int column;
	cin >> column;

	//Top:
	doPrint ( ' ', column - 1 );
	cout << "*" << endl;

	//Mid:
	int spaceOut = column - 2;
	int spaceIn = 1;

	for ( int i = 2; i < column; i++ ) {
		doPrint ( ' ', spaceOut ); cout << "*";
		doPrint ( ' ', spaceIn ); cout << "*";
		cout << "\n";

		spaceOut--;
		spaceIn += 2;
	}

	//End:
	doPrint ( '*', column * 2 - 1 ); cout << "\n";

	system ( "pause" );
}
