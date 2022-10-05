#include<bits/stdc++.h>
#define MAX 1001
using namespace std;

int n, num[MAX];

void init() {
	cin >> n;
	for ( int i = 0; i < n; i++ )
		cin >> num[i];
}

void display() {
	for ( int i = 0; i < n; i++ )
		cout << num[i] << " ";
	cout << endl;
}

int main() {
	int t; cin >> t;
	while ( t-- ) {
		init();
		next_permutation(num, num + n);
		display();
	}
}