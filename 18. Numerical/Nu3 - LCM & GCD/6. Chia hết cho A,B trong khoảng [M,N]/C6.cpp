#include <bits/stdc++.h> 
using namespace std;

//BCNN:
int LCM ( int a, int b ) {
	int step = std::max ( a, b );
	for ( int i = step; i < a*b; i += step )
		if ( i % a == 0 && i % b == 0 )
			return i;
}

//Số các số chia hết cho X trong khoảng [M,N]:
int Divide ( int x, int m, int n ) {
	int begin;
	if ( m % x == 0 ) begin = m;
	else begin = x * ( int ) ( m / x ) + x;
	int end = x * ( int ) ( n / x );
	return (( end - begin ) / x) + 1;
}
 
int main () {
	int t, m, n, a, b; cin >> t;
	while ( t-- ) {
		cin >> m >> n >> a >> b;
		cout << Divide ( a, m, n ) + Divide ( b, m, n ) - Divide ( LCM ( a, b ), m, n ) << endl;
	} system ( "pause" );
}