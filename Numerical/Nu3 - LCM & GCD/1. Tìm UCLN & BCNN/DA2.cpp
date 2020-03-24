#include<bits/stdc++.h>
using namespace std;

//Tìm UCLN(a,b)
long long GCD ( long long a, long long b ) { //GCD - Greatest Common Divisor : UCLN 
	if ( a == 0 ) return b;
	return GCD( b % a, a );
}

// Tìm BCNN(a,b)
long long LCM ( long long a, long long b ) { //LCM - Least Common Multiple : BCNN
	return( a*b / GCD ( a, b ) );
}

int main () {
	long long a, b, n;
	cin >> n;
	//for ( int i = 1; i <= n; i++ ) {
	while ( n-- ) {
		cin >> a >> b;
		cout << LCM ( a, b ) << " " << GCD ( a, b ) << endl;
	}

	system ( "pause" );
	return 0;
}
