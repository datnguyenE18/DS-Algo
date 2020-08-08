// Liệt kê các SNT từ 1 đến n
#include <bits/stdc++.h>
using namespace std;

int main () {
	int n ; cin >> n;

	// Mảng đánh dấu, mark[i] == true thì i là số nguyên tố
	vector<bool> mark ( n + 1, true );
	mark[0] = mark[1] = false;

	for ( int i = 2; i <= n; i++ ) {
		if ( mark[i] ) {
			for ( int j = i * 2; j <= n; j += i ) {
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