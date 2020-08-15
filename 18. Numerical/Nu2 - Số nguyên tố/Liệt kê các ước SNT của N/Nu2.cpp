#include <bits/stdc++.h> 
typedef long long int ll;
using namespace std;

void solve(ll n) {
	// B1: Kiểm tra và in ra ước số 2
	while ( n % 2 == 0 ) {
		cout << 2 << " ";
		n /= 2;
	}

	// B2: Kiểm tra các số lẻ và in ra các ước lẻ
	for ( ll i = 3; i <= sqrt(n); i += 2 ) {
		while ( n % i == 0 ) {
			cout << i << " ";
			n /= i;
		}
	}

	// Cuối cùng số n còn lại sau khi chia dần bên trên nếu nó vẫn lớn hơn 2 thì nó chia hết cho chính nó
	if ( n > 2 )
		cout << n;
	cout << endl;
}

int main() {
	int t; cin >> t;
	ll n;
	while ( t-- ) {
		cin >> n;
		solve(n);
	}
}
