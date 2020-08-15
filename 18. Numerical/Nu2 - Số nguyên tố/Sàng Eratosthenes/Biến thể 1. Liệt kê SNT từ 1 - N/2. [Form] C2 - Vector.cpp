#include <bits/stdc++.h> 
using namespace std;

void Eratosthenes(int n) {
	// Ban đầu đánh dấu tất cả các số từ 1 - N đều là SNT
	vector<bool> mark(n + 1, true); // Mảng đánh dấu, mark[i] == true thì i là số nguyên tố

	mark[0] = mark[1] = false; // 0 và 1 không phải SNT

	for ( int i = 2; i <= sqrt(n); i++ )
		if ( mark[i] )
			// Xuất phát từ i * i vì các hợp số trước i * 2, i * 3, ..., i * (i - 1) đó đều đã được xét và bị đánh dấu:
			for ( int j = i * i; j <= n; j += i )
				mark[j] = false;

	// In ra các số nguyên tố trong đoạn từ 1 đến N
	for ( int i = 2; i <= n; i++ )
		if ( mark[i] )
			cout << i << " ";
	cout << endl;
}

int main() {
	int n, t; cin >> t;
	while ( t-- ) {
		cin >> n;
		Eratosthenes(n);
	}
}
