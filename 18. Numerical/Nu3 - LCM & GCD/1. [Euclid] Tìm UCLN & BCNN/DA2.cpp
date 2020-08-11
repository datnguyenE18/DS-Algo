#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll GCD(ll a, ll b) {
	if ( a == 0 ) return b; // giả sử a = 0 & b = 3 thì dừng lại ở bước này
	// Còn nếu a = 3 & b = 0 thì sẽ nhảy sang bước sau chắc chắn không có 3 / 0 vì vậy sẽ không xuất hiện a % b mà chỉ có b % a, 
	// thử đặt vào 1 trong 2 vị trí  return GCD(..., ...) và đổi vị trí còn lại bằng a hoặc b sau đó thử với phép đơn giả thì ta có code sau:
	return GCD(b % a, a);
}

ll LCM(ll a, ll b) {
	return ( a * b ) / GCD(a, b);
}

int main() {
	ll a, b;
	int t; cin >> t;
	while ( t-- ) {
		cin >> a >> b;
		cout << LCM(a, b) << " " << GCD(a, b) << endl;
	}
}