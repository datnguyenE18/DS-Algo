#include<bits/stdc++.h>
using namespace std;

int deci; // Decimal Numbering System : Hệ đếm thập phân
stack <int> bin; // Binary Numbering System

void Dec_to_Bin () {
	while ( deci ) {
		bin.push ( deci % 2 );
		deci /= 2;
	}
	int l = bin.size ();
	while ( l-- ) {
		cout << bin.top ();
		bin.pop ();
	} cout << "\n";
}

int main () {
	cin >> deci;
	Dec_to_Bin ();
	system ( "pause" );
}