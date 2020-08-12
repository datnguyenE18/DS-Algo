// GCD(a, x, y): x, y là số lần lặp lại a
#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;

ll gcd(ll a, ll b) {
	if ( a == 0 ) return b;
	return gcd(b % a, a);
}

void find_gcd(ll a, ll x, ll y) {
	ll g = gcd(x, y);
	for ( int i = 0; i < g; i++ )
		cout << a;
	cout << endl;
}

int main() {
	ll a, x, y;
	int t; cin >> t;
	while ( t-- ) {
		cin >> a >> x >> y;
		find_gcd(a, x, y);
	}
}
