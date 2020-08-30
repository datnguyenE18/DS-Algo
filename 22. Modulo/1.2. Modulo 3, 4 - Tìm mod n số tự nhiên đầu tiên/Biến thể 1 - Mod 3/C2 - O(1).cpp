#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

ll findSum(int N, ll K) {
	ll ans = 0,
		y = N / K, //có y đoạn, mỗi đoạn có tổng s = 1 + 2 +... + K-1 
		x = N % K; //còn lại s = 1 + 2 +.. + x 

	ans = ( K * ( K - 1 ) / 2 ) * y; //y đoạn có tổng s = 1 + 2 + ... + K-1
	ans += ( x * ( x + 1 ) ) / 2; //cộng thêm với tổng x số tự nhiên đầu tiên  
	return ans;
}

int main() {
	int N, T; cin >> T;
	ll K;
	while ( T-- ) {
		cin >> N >> K;
		cout << findSum(N, K) << endl;
	}
}
