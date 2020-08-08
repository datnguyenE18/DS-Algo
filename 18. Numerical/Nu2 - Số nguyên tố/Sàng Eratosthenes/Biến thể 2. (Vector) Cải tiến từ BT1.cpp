#include <bits/stdc++.h>
using namespace std;

int main () {
	int n ; cin >> n;

	// Mảng đánh dấu, mark[i] == true thì i là số nguyên tố
	vector<bool> mark ( n + 1, true );
	mark[0] = mark[1] = false;

	for ( int i = 2; i*i <= n; i++ ) {
		if ( mark[i] ) {
			// Xuất phát từ `i*i` vì các hợp số trước đó đều đã bị đánh dấu
			for ( int j = i*i; j <= n; j += i ) {
				mark[j] = false;
			}
		}
	}

	// Xuất các số nguyên tố trong đoạn từ 1 đến n
	for ( int i = 2; i <= n; i++ ) {
		if ( mark[i] ) cout << i << " ";
	}

	system ( "pause" );
	return 0;
}