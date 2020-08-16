#include<iostream>
using namespace std;

void phan_tich_SNT(int  N) {
	int exp; // Số mũ
	for ( int i = 2; i <= N; i++ ) {
		exp = 0;
		while ( N % i == 0 ) {
			exp++;
			N /= i;
		}
		if ( exp ) {
			cout << i;
			if ( exp >= 1 ) cout << " " << exp;
			if ( N > i ) cout << " ";
		}
	}
	cout << endl;
}

int main() {
	int N, T; cin >> T;
	while ( T-- ) {
		cin >> N;
		phan_tich_SNT(N);
	}
}