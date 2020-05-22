#include<bits/stdc++.h>
using namespace std;
#define MAX 20

int n, k, num[MAX];

void display() {
	for ( int i = 1; i <= k; i++ ) {
		cout << num[i];
	} cout << " ";
}

void Try(int i) {
	for ( int j = num[i - 1] + 1; j <= n - k + i; j++ ) {
		num[i] = j;
		if ( i == k ) {
			display();
		} else Try(i + 1);
	}
}

int main() {
	int t; cin >> t;
	while ( t-- ) {
		num[0] = 0;
		cin >> n >> k;
		Try(1);
		cout << "\n";
	}
}