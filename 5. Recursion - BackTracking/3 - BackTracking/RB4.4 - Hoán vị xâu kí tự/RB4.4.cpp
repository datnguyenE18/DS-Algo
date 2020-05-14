#include <bits/stdc++.h>
using namespace std;
#define MAX 10

int X[MAX], n, chuaxet[MAX];
string S;

void Init(void) {
	cin >> S;
	n = S.length();
	for ( int i = 0; i < n; i++ )
		chuaxet[i] = true;
}

void Result(void) {
	for ( int i = 0; i < n; i++ )
		cout << S[X[i]];
	cout << " ";
}

void Try(int i) {
	for ( int j = 0; j < n; j++ ) {
		if ( chuaxet[j] ) {
			X[i] = j;
			chuaxet[j] = false;
			if ( i == n - 1 ) Result();
			else Try(i + 1);
			chuaxet[j] = true;
		}
	}
}

int main(void) {
	int T; cin >> T;
	while ( T-- ) {
		Init();
		Try(0);
		cout << endl;
	}
}
