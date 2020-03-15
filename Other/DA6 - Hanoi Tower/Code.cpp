#include<bits\stdc++.h>
using namespace std;

void hanoi ( int n, char Start, char temp, char Target ) {
	if ( n == 1 ) cout << Start << " -> " << Target << endl;
	else {
		hanoi ( n - 1, Start, Target, temp );
		cout << Start << " -> " << Target << endl; //or: hanoi ( 1, Start, temp, Target );
		hanoi ( n - 1, temp, Start, Target );
	}
}

int main () {
	int n = 3;
	hanoi ( n, 'A', 'B', 'C' );
	system ( "pause" );
}