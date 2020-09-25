#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll GCD(ll x, ll y) {
	if ( x == 0 ) return y;
	return GCD(y % x, x);
}

//Rút gọn số b. Tức thay b = b % a. Vì UCLN (a,b) = UCLN (a, b % a)
// Tìm mod dựa vào bài DA5 : tìm số dư a / b với b vô cùng lớn
ll reduce_b(ll a, string b) {
	ll mod = 0;
	for ( int i = 0; i < b.length(); i++ )
		mod = ( mod * 10 + b[i] - '0' ) % a; // b[i] - '0'để chuyển string b[i] thành số nguyên Int 
	return mod;
}

//Tìm UCLN của a và b % a
ll GCD_mod(ll a, string b) {
	ll num = reduce_b(a, b);
	return GCD(a, num);
}

int main() {
	ll a;
	string b;
	int t;  cin >> t;
	while ( t-- ) {
		cin >> a;
		cin >> b;
		cout << GCD_mod(a, b) << endl;
	}
}