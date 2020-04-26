//Không tối ưu bằng Back_Tracking
#include<bits/stdc++.h>
using namespace std;

int n, c[50], a[50], stop = 0, s;

void sinh ( int k ) {
	int i = k;
	while ( i > 0 && c[i] == n - k + i ) i--;
	if ( i <= 0 )  stop = 1;
	else {
		c[i] ++;
		for ( int j = i + 1; j <= k; j++ ) {
			c[j] = c[j - 1];
		}
	}
}

int main () {
	cin >> n >> s;
	for ( int i = 1; i <= n; i++ ) cin >> a[i];
	for ( int i = 1; i <= n; i++ ) {
		stop = 0;
		for ( int j = 1; j <= i; j++ ) c[j] = j;

		while ( !stop ) {
			int res = 0;
			for ( int j = 1; j <= i; j++ ) res += a[c[j]];
			if ( res == s ) {
				cout << i << endl;
				return 0;
			}
			sinh ( i );
		}
	}
}