#include<bits/stdc++.h>
using namespace std;
const unsigned int p = 1e9 + 7;

void nCrModp(int n, int r) {
	// Tam giác Pascal nCr
	vector<int> C(r + 1, 0);
	C[0] = 1; // Phần tử đầu tiên là 1

	// Xây dựng tam giác Pascal từ C[0] = 1:
	for ( int i = 1; i <= n; i++ )
		for ( int j = min(i, r); j > 0; j-- )
			// nCj = (n-1)Cj + (n-1)C(j-1); 
			C[j] = ( C[j] + C[j - 1] ) % p;

	cout << C[r] << endl;
}

int main() {
	int t, n, r; cin >> t;
	while ( t-- ) {
		cin >> n >> r;
		nCrModp(n, r);
	}
}