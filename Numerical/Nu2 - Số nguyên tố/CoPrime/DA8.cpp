// chia 1, 2,.., N thanh ha tap
//so cho hieu cua tong hai tap la M
// hai tong la co-prime   
#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll;

ll GCD ( ll a, ll b ) { 
	if ( a == 0 ) return b;
	return GCD ( b % a, a );
}

bool Test ( ll n, ll m ) {
	// tinh tong tu 1 den n     
	ll total_sum = ( n * ( n + 1 ) ) / 2;
	//tinh tong tap thu nhat
	ll sum_s1 = ( total_sum + m ) / 2;
	// tinh tong tap thu 2     
	ll sum_s2 = total_sum - sum_s1;
	if ( total_sum < m ) //neu dieu nay xay ra
		return false;
	if ( sum_s1 + sum_s2 == total_sum &&
		 sum_s1 - sum_s2 == m ) //neu dieu nay xay ra

		 return ( GCD ( sum_s1, sum_s2 ) == 1 );
	return false;
}
// Driver code 
int main () {
	ll T, n, m; cin >> T;
	while ( T-- ) {
		cin >> n >> m;
		if ( Test ( n, m ) ) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	system ( "pause" );
	return 0;
}
