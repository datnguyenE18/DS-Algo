#include<bits/stdc++.h>
using namespace std;

vector<int> sortByHeight ( vector<int> a ) {
	vector<int> storage;

	for ( int i = 0; i < a.size (); i++ ) {
		if ( a[i] != -1 ) storage.push_back ( a[i] );
	}

	sort ( storage.begin (), storage.end () );
	int count = 0;

	for ( int j = 0; j < a.size (); j++ ) {
		if ( a[j] != -1 ) {
			a[j] = storage[count];
			count++;
		}
	} return a;
}



int main () {
	vector<int> a;
	int n; cin >> n;
	for ( int i = 0; i < n; i++ ) {
		int temp = 0; cin >> temp;
		a.push_back ( temp );
	}

	for ( int i = 0; i < n; i++ ) {
		cout << sortByHeight ( a )[i] << ", ";
	}

	system ( "pause" );
}