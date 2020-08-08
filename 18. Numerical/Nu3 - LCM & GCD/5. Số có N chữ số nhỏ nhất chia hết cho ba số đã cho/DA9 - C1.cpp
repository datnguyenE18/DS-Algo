#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//Tìm UCLN của hai số theo Euclid:
ll GCD ( ll a, ll b ) {
	if ( b == 0 ) return a;
	else
		return GCD ( b, a%b );
}

// Tìm BCNN của 3 số dựa vào UCLN:
ll LCM ( int a, int b, int c ) {
	ll lcmab = ( ll ) ( a*b ) / GCD ( a, b );
	ll lcm = ( ll ) ( lcmab * c ) / GCD ( lcmab, c );
	return lcm;
}

// Giải quyết vấn đề còn lại:
ll solution ( int n, int a, int b, int c ) {
	ll lcm = LCM ( a, b, c );
	ll n_digit = ( ll ) pow ( 10, n - 1 );
	ll temp = n_digit % lcm;
	if ( temp == 0 ) return n_digit;
	n_digit = n_digit + ( lcm - temp );
	if ( n_digit < ( ll ) pow ( 10, n ) ) return n_digit;
	else return 0;
}

int main () {
	int T; cin >> T;
	ll  n, a, b, c;
	while ( T-- ) {
		cin >> a >> b >> c >> n;
		ll Result = solution ( n, a, b, c );
		if ( Result != 0 )
			cout << Result << endl;
		else
			cout << "-1" << endl;
	}

	system ( "pause" );
	return 0;
}