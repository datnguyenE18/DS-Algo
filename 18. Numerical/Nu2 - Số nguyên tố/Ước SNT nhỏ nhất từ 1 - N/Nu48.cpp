#include<bits/stdc++.h> 
using namespace std;
 
void Solution ( int n ) {
	int ans[n + 1];
	memset ( ans, false, sizeof( ans ) );
	ans[1] = 1;
 
	for ( int i = 2; i <= n; i++ ) {
		if ( ans[i] == 0 ) {
			ans[i] = i;
			for ( int j = i * i; j <= n; j += i ) {
				if ( ans[j] == 0 )
					ans[j] = i;
			}
		}
	}
	for ( int i = 1; i <= n; i++ ) cout << ans[i] << " ";
	cout << endl;
}
 
int main () {
	int T, n; cin >> T;
	while ( T-- ) {
		cin >> n;
		Solution ( n );
	} system ( "pause" );
}