#include<bits\stdc++.h>
using namespace std;
typedef long long int ll;

// Tìm UCLN theo Euclid:
ll GCD ( ll x, ll y ) {
	if ( !x ) return y;
	return GCD ( y % x, x );
}

//Rút gọn số b. Tức thay b = b % a. Vì UCLN (a,b) = UCLN (a, b % a)
// Tìm mod dựa vào bài DA5 : tìm số dư a / b với b vô cùng lớn
ll reduce_b ( ll a, string b ) {
	ll mod = 0;
	for ( int i = 0; i < b.length (); i++ ) {
		mod = ( mod * 10 + b[i] - '0' ) % a; //b[i]-'0'để chuyển string b[i] thành số nguyên Int 
	} return mod; // return modulo 
}

//Tìm UCLN của a và b % a
ll GCD_mod ( ll a, string b ) {
	ll num = reduce_b ( a, b ); //num trở thành số ll
	return GCD ( a, num );
}

int main () {
	int T;
	ll a;
	string b;
	cin >> T;
	while ( T-- ) {
		cin >> a >> b;
		cout << GCD_mod ( a, b );
	}

	system ( "pause" );
	return 0;
}