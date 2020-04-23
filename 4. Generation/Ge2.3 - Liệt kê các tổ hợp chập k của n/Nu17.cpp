#include <bits/stdc++.h>
using namespace std;

int n, k, check;
int x[16];


void orig_conf () {
	for ( int i = 1; i <= k; i++ ) x[i] = i;
}

void display () {
	for ( int i = 1; i <= k; i++ ) cout << x[i];
}

void solve () {
	int i = k; // Xuất phát từ phần tử cuối cùng của tổ hợp
	while ( i > 0 && x[i] == n - k + i ) i--; //Tìm phần tử X[i]N-K+i
	if ( i > 0 ) { //Nếu i chưa vượt quá phần tử cuối cùng
		x[i]++;
		for ( int j = i + 1; j <= k; j++ ) { //Từ phần tử thứ j +1 đến k
			x[j] = x[i] + j - i;
		}
	} else check = 1; //OK = 1 nếu đã đến tập con cuối cùng
}

int main () {
	int t; cin >> t;

	while ( t-- ) {
		cin >> n >> k;
		orig_conf ();
		check = 0;
		do {
			display ();
			cout << " ";
			solve ();
		} while ( check != 1 );
		cout << "\n";
	} system ( "pause" );
}