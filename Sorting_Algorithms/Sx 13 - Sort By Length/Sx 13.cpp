#include<bits/stdc++.h>
using namespace std;

vector<string> sortByLength ( vector<string> inputArray ) {
	int n = ( int ) inputArray.size ();
	for ( int i = 0; i < n; ++i )
	for ( int j = 0; j < n - 1; ++j )
	if ( inputArray[j].length () > inputArray[j + 1].length () )
		swap ( inputArray[j], inputArray[j + 1] );
	return inputArray;
}

int main () {
	vector<string> inputArray = { "abc", "", "aaa", "a", "zz" };
	int n = sortByLength ( inputArray ).size ();
	cout << "{ ";
	for ( int i = 0; i < n - 1; i++ ) cout << "\"" << sortByLength ( inputArray )[i] << "\", ";
	cout << "\"" << sortByLength ( inputArray )[n - 1] << "\" }\n";
	system ( "pause" );
}