#include<iostream>
using namespace std;
int n, a[550], stop;
void sinh () {
	int i = n;
	while ( a[i] == 1 ) { a[i] = 0; i--; }
	if ( i == 0 ) stop = 1;
	else a[i] = 1;
}
int main () {
	int T; cin >> T;
	while ( T-- ) {
		int k, danhdau = 0; cin >> k;
		for ( n = 0; n <= 500; n++ ) {
			stop = 0;
			while ( stop == 0 ) {
				long long  tong = 0;
				for ( int j = 1; j <= n; j++ ) tong = tong * 10 + a[j];
				if ( tong != 0 && tong * 9 % k == 0 ) {
					cout << tong * 9 << endl;
					danhdau = 1;
					break;
				}
				sinh ();
			}
			if ( danhdau == 1 ) break;
		}
	}
	return 0;
}