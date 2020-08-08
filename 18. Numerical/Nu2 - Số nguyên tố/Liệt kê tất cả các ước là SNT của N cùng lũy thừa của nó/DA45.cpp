#include<iostream>
using namespace std;

void phan_tich_SNT ( int  N ) {
	int dem;
	for ( int i = 2; i <= N; i++ ) {
		dem = 0;
		while ( N % i == 0 ) {
			dem++;
			N /= i;
		}
		if ( dem ) {
			cout << i;
			if ( dem >= 1 ) cout << " " << dem;
			if ( N > i ) cout << " ";
		}
	}
	cout << endl;
}

int main ( ) {
	int N;
	int T; cin >> T;
	while ( T-- ) {
		cin >> N;
		phan_tich_SNT ( N );
	}

	system ( "pause" );
	return 0;
}