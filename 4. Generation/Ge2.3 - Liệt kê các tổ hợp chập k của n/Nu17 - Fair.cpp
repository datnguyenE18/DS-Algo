#include<bits/stdc++.h>
using namespace std;

int n, k, num[16];
bool check;

void init() {
	check = true;
	cin >> n >> k;
	for ( int i = 1; i <= k; i++ )
		num[i] = i;
}

void next_Subset() {
	for ( int i = k; i > 0; i-- ) {
		if ( num[i] == n - k + i ) continue;
		else {
			num[i] ++;
			for ( int j = i + 1; j <= k; j++ )
				num[j] = num[i] + j - i;
			return;
		}
	}
	check = false;
}

void display() {
	for ( int i = 1; i <= k; i++ )
		cout << num[i];
	cout << " ";
}

int main() {
	int t; cin >> t;
	while ( t-- ) {
		init();
		do {
			display();
			next_Subset();
		} while ( check );
		cout << "\n";
	}
}