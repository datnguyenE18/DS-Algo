#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool checkPalindrome ( std::string inputString ) {
	int n = inputString.length ();
	for ( int i = 0; i <= n / 2; i++ ) {
		for ( int j = ( n - i - 1 ); j >= n / 2; j++ ) {
			if ( inputString[i] != inputString[j] ) {
				return false;
			} break;
		}
	} return true;
}


int main () {
	string inputString;
	int T; cin >> T;
	while ( T-- ) {
		fflush ( stdin );// xóa bộ nhớ đệm
		getline ( cin, inputString );
		if ( checkPalindrome ( inputString ) ) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	system ( "pause" );
	return 0;
}