#include<bits/stdc++.h>
using namespace std;

int cmp ( int x, int y ) { return ( x > y ); }
int searchElement ( vector<int> a, int n ) {
	int count = 1;
	int l = a.size ();
	if ( n > l ) return -1;
	sort ( a.begin (), a.end (), cmp );
	for ( int i = 0; i < l - 1; i++ ) {
		if ( a[i] == a[i + 1] ) continue;
		if ( a[i] > a[i + 1] ) {
			if ( count == n ) return a[i];
			count++;
		}
	} return -1;
}


int main () {
	vector<int>a = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
	int n = 7;
	cout << searchElement ( a, n );
	system ( "pause" );
}