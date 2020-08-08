#include <iostream>
using namespace std;

int main () {
	int n;
	cin >> n;

	//Top
	for ( int i = 1; i < n; i++ ) {
		for ( int j = n - i; j > 0; j-- )
			cout << " ";
		for ( int k = 1; k <= 2 * i - 1; k++ ) {
			if ( k == 2 * i - 1 || k == 1 )
				cout << "*";
			else cout << " ";
		}
		cout << endl;
	}

	//End:
	for ( int i = 1; i <= 2 * n - 1; i++ ) cout << "*"; cout << "\n";
	system ( "pause" );
}


