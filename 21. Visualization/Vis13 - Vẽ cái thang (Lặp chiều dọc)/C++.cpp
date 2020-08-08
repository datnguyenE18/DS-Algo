#include <iostream>
using namespace std;

void doPrint ( char c, int num ) {
	for ( int i = 1; i <= num; i++ ) cout << c;
}

void drawBlog ( int spa, int wi ) {
	doPrint ( '*', wi );
	cout << "\n";
	for ( int i = 1; i <= spa - 1; i++ ) {
		cout << "*";
		doPrint ( ' ', wi - 2 );
		cout << "*";
		cout << "\n";
	}
}


int main () {
	int hi, wi, spa;
	cin >> hi >> wi >> spa;

	//top:
	cout << "*";
	doPrint ( ' ', wi - 2 );
	cout << "*" << "\n";

	//body
	for ( int i = 1; i <= ( hi - 1 ) / spa; i++ ) drawBlog ( spa, wi );
	if ( int rest = ( hi - 1 ) % spa ) drawBlog ( rest, wi );

	system ( "pause" );
}