#include <iostream>
using namespace std;

int main ( ) {
	// Declare integer variables
	int n, digit;
	// Read and save variables
	cin >> n;
	digit = 0;
	// Count numbers of digit using while loop
	while ( n != 0 ) {
		n /= 10;
		digit++;
	}
	// Print the number of digits on a new line
	cout << digit << endl;

	system ( "pause" );
	return 0;
}