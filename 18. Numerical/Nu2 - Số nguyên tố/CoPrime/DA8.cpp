#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll;

ll GCD(ll a, ll b) {
	if ( a == 0 ) return b;
	return GCD(b % a, a);
}

bool Test(ll n, ll m) {
	ll total_sum = ( n * ( n + 1 ) ) / 2, // tính tổng từ 1 đến n
		sum_s1 = ( total_sum + m ) / 2, //tính tổng tập thứ nhất
		sum_s2 = total_sum - sum_s1; // tính tổng tập thứ 2
	
	if ( total_sum < m )
		return false;
	if ( sum_s1 + sum_s2 == total_sum && sum_s1 - sum_s2 == m )
		return ( GCD(sum_s1, sum_s2) == 1 );

	return false;
}

int main() {
	ll n, m;
	int t; cin >> t;
	while ( t-- ) {
		cin >> n >> m;
		if ( Test(n, m) ) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
