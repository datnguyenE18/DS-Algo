#include<bits/stdc++.h>
using namespace std;

int t;
string gray;

void Gray_to_Bin () {
	string bin = "";
	bin += gray[0];
	for ( int i = 1; i < gray.length (); i++ ) {
		if ( gray[i] != bin[i - 1] ) bin += "1";
		else bin += "0";
	} cout << bin << endl;
}

int main () {
	cin >> t;
	while ( t-- ) {
		cin >> gray;
		Gray_to_Bin ();
	} system ( "pause" );
}