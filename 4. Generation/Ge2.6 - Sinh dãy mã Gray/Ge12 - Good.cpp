#include<bits/stdc++.h>
using namespace std;

class Gray {
	int m;
	long n;
	int A[65538];
	public:
	void nhap();
	void xuat();

};

void Gray::xuat() {
	int b[20];

	for ( int i = 0; i < n; i++ ) {
		int k = 0;
		int u = A[i];
		while ( u > 0 ) {
			b[k++] = u % 2;
			u /= 2;
		}
		for ( int j = k + 1; j <= m; j++ ) cout << "0";
		while ( k >= 1 ) cout << b[--k];
		cout << " ";
	}

}

void Gray::nhap() {
	cin >> m;
	A[0] = 0;
	A[1] = 1;
	int p = 1;
	n = 2;
	for ( int i = 2; i <= m; i++ ) {
		p *= 2;
		int u = 2 * n - 1;
		for ( int j = n; j <= u; j++ ) A[j] = A[u - j] + p;
		n *= 2;
	}
}

int main() {
	int t; cin >> t;
	Gray G;
	while ( t-- ) {
		G.nhap();
		G.xuat();
		cout << "\n";
	}
}