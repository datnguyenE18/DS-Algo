#include<bits/stdc++.h>
using namespace std;

// Tổng chữ số:
int sum_of_digs(int n) {
	int sum = 0;
	while ( n ) {
		sum += n % 10;
		n /= 10;
	} return sum;
}

// Tổng ước:
int sum_of_mea(int n) {
	int sum = 0;

	for ( int i = 2; i <= sqrt(n); i++ ) {
		while ( n % i == 0 ) {
			sum += sum_of_digs(i);
			n /= i;
		}
	}
	if ( !sum ) return 0; // Nếu sum = 0 thì trả về 0
	else if ( n > 2 ) sum += sum_of_digs(n);
	return sum;
}

int main() {
	int n, T; cin >> T;
	while ( T-- ) {
		cin >> n;
		if ( sum_of_digs(n) == sum_of_mea(n) ) {
			cout << "YES" << endl;
			continue;
		} cout << "NO" << endl;
	}
}