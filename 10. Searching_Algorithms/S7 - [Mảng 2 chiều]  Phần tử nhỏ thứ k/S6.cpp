#include<bits/stdc++.h>
using namespace std;

int searchElement02 ( vector<vector<int>> a, int k ) {
	int n = a.size (); //số hàng
	vector<int> temp;
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			temp.push_back ( a[i][j] );
		}
	} sort ( temp.begin (), temp.end () );
	
	int count = 1;
	int l = temp.size ();
	if ( k > l ) return -1;
	for ( int i = 0; i < l - 1; i++ ) {
		if ( temp[i] == temp[i + 1] ) continue;
		if ( temp[i] < temp[i + 1] ) {
			if ( count == k ) return temp[i];
			count++;
		}
	} return -1;
}



int main () {
	vector<vector<int>>arr = { { 2, 2, 2 }, { 2, 2, 2 }, { 2, 2, 2 } };
	int k = 10;
	cout << searchElement02 ( arr, k );

	system ( "pause" );
}