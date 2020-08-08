#include <bits/stdc++.h>
using namespace std;

int commonCharacterCount ( string s1, string s2 ) {
	int n1 = s1.length (), n2 = s2.length (), dem = 0;
	for ( int i = 0; i < n1; i++) {
		for ( int j = 0; j < n2; j++ ) {
			if ( s1[i] == s2[j] ) {
				dem++;
				s1.erase ( s1.begin () + i );
				s2.erase ( s2.begin () + j );
				n1--; n2--; i--;
				break;
			} 
		}
	}
	return dem;
}




int main () {
	string s1 = "abca", s2 = "xyzbac"; 
	cout << commonCharacterCount ( s1, s2 ) << endl;
	system ( "pause" );
}