#include <bits/stdc++.h>
using namespace std;

int main () {
	string begin, end;
	cin >> begin;
	end = begin;
	next_permutation ( end.begin (), end.end () );
	if ( begin < end ) cout << end << endl;
	else cout << 0 << endl;
	system ( "pause" );
}