#include<bits/stdc++.h>
using namespace std;

vector<int> uniqueArray ( vector<int>arr ) {
	vector<int>b;
	for ( int i : arr ) {
		bool Push = true;
		for ( int j : b ) if ( i == j ) {
			Push = false;
			break;
		} if ( Push ) b.push_back ( i );
	} return b;
}


int main () {
	vector<int>arr = { 1, 2, 3, 2, 4, 1, 10 };
	for ( int i : uniqueArray ( arr ) ) cout << i << ", ";

	system ( "pause" );
}