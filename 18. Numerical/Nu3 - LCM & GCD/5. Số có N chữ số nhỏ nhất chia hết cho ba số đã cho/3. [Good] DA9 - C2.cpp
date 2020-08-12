#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//Tìm UCLN của hai số theo Euclid:
ll GCD(ll a, ll b) {
	if ( b == 0 ) return a;
	return GCD(b, a % b);
}

// Tìm BCNN của 3 số dựa vào UCLN:
ll LCM(int a, int b, int c) {
	ll lcmab = (ll) ( a * b ) / GCD(a, b),
		lcm = (ll) ( lcmab * c ) / GCD(lcmab, c);
	return lcm;
}

// Giải quyết vấn đề còn lại:
ll solution(int n, int a, int b, int c) {
	ll lcm = LCM(a, b, c),
		n_digit = (ll) pow(10, n - 1),
		temp = n_digit % lcm;

	if ( temp == 0 ) return n_digit;

	n_digit = n_digit + ( lcm - temp );

	if ( n_digit < (ll) pow(10, n) )
		return n_digit;
	return 0;
}

int main() {
	int t; cin >> t;
	ll  n, a, b, c;

	while ( t-- ) {
		cin >> a >> b >> c >> n;
		ll Result = solution(n, a, b, c);

		if ( Result != 0 )
			cout << Result << endl;
		else cout << "-1" << endl;
	}
}