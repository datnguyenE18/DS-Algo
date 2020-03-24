#include <bits/stdc++.h> 
using namespace std;

int solution ( int n, int k ) {
	int dem = 0;
	while ( n % 2 == 0 && dem < k ) {
		n /= 2;
		dem++; 
	} if ( dem == k ) return 2;

	int i = 3;
	for ( ; i <= sqrt ( n ); i += 2 ) {
		while ( n % i == 0  && dem < k) {
			n /= i;
			dem++; cout << dem << endl; //
		} if ( dem == k ) return i;
	} 
	cout << dem << endl;//
	if ( n > 2 && dem < k ) dem++; cout << dem << endl;//
	if ( dem != k ) return -1;
	else return n;
}

int main () {
	int n, k, T; cin >> T;
	while ( T-- ) {
		cin >> n >> k;
		cout << solution ( n, k ) << endl;
	} system ( "pause" );
}