#include<bits/stdc++.h>
using namespace std;

string s;
int n;
char x[1000];

void display() {
	for (int i = 0; i < n; i++) cout << x[i];
	cout << " ";
}

void init() {
	n = s.size();
	for (int i = 0; i < n; i++)
		x[i] = s[i];
}

int main() {
	int t; cin >> t;
	while (t--) {
		s = "";
		cin >> s;
		init();
		while (prev_permutation(x, x + n)) {
			display();
		}
		init();
		do {
			display();
		} while (next_permutation(x, x + n));
		cout << "\n";
	}
	return 0;
}