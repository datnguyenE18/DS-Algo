#include <bits/stdc++.h> 
using namespace std;

//UCLN - (Euclid)
int UCLN ( int a, int b ) {
	if ( a == 0 ) return b;
	return UCLN ( b % a, a );
}

//Số các số chia hết cho X trong khoảng [M,N]:
int Divide ( int x, int m, int n ) {
	int begin;
	if ( m % x == 0 ) begin = m;
	else begin = x * ( int ) ( m / x ) + x;
	int end = x * ( int ) ( n / x );
	return ( ( end - begin ) / x ) + 1;
}

int main () {
	int t, m, n, a, b; cin >> t;
	while ( t-- ) {
		cin >> m >> n >> a >> b;
		cout << Divide ( a, m, n ) + Divide ( b, m, n ) - Divide ( ( ( a*b ) / UCLN ( a, b ) ), m, n ) << endl;
	} system ( "pause" );
}
