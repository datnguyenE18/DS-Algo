#include <iostream>
using namespace std;

//2 sides:
void side ( int width ) {
	for ( int i = 1; i <= width; i++ ) cout << "*";
	cout << "\n";
}

//Mid:
void mid ( int width ) {
	for ( int i = 1; i <= width; i++ ) {
		if ( i == 1 || i == width ) cout << "*";
		else cout << " ";
	} cout << "\n";
}

int main () {
	int length, width;
	cout << "Length: "; cin >> length;
	cout << "Width: "; cin >> width;

	side ( width );
	for ( int i = 1; i <= length - 2; i++ ) mid ( width );
	side ( width );
	cout << endl;

	system ( "pause" );
}


