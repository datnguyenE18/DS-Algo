#include<bits/stdc++.h> 
using namespace std;

int Solution(int A[], int n) {
	sort(A, A + n);
	int d = A[n - 1] - A[0];
	vector <int> v;

	for ( int i = 1; i * i <= d; i++ )
		if ( d % i == 0 ) {
			v.push_back(i);
			if ( i != d / i )
				v.push_back(d / i);
		}

	int ans = 0;
	for ( int i = 0; i < v.size(); i++ ) {
		int temp = A[0] % v[i];
		int j;
		for ( j = 1; j < n; j++ )
			if ( A[j] % v[i] != temp )
				break;
		if ( j == n )
			ans++;
	}
	return ans;
}

int main() {
	int T, n, *A; cin >> T;
	while ( T-- ) {
		cin >> n; A = new int[n];
		for ( int i = 0; i < n; i++ ) cin >> A[i];
		cout << Solution(A, n) << endl;
	}
}