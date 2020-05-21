/*
**Next_binary_strings
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 11111

char bit[MAX];

void Next_Bits_String() {
	int n = strlen(bit);
	int i = n - 1;
	for ( ; i >= 0 && bit[i] == '1'; i-- ) {
		bit[i] = '0';
	}
	if ( i >= 0 ) bit[i] = '1';
}

int main() {
	int t; cin >> t;
	while ( t-- ) {
		cin >> bit;
		Next_Bits_String();
		cout << bit << endl;
	}
}
