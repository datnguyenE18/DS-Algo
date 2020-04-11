#include <bits/stdc++.h>
using namespace std;

int main () {
	int t; cin >> t;
	while ( t-- ) {
		int stt; cin >> stt;
		string s; cin >> s;
		bool kq = next_permutation ( s.begin (), s.end () );
		if ( kq ) cout << stt << " " << s << endl;
		else cout << stt << " BIGGEST" << endl;
	} return 0;
}