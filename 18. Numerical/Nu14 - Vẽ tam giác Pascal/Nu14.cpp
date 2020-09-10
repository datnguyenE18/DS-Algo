#include<bits/stdc++.h>
using namespace std;

int fatorial(int n) {
	int f;
	for ( f = 1; n > 1; n-- )
		f *= n;
	return f;
}

int nCk(int n, int k) {
	return fatorial(n) / ( fatorial(k) * fatorial(n - k) );
}

int main() {
	int n;
	cout << "So  hang n = "; cin >> n;
	cout << "Tam gia Pascal\n";

	for ( int i = 0; i <= n; i++ ) {
		for ( int j = 0; j <= n - i; j++ )
			cout << "  ";

		for ( int j = 0; j <= i; j++ )
			cout << "   " << nCk(i, j);

		cout << endl;
	}
}