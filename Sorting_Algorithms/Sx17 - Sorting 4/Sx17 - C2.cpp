#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 1;

int nA, nB, X[maxN];

void init() {
	cin >> nA >> nB;
	for ( int i = 0; i < nA; i++ )
		cin >> X[i];
	for ( int i = nA; i < nA + nB; i++ )
		cin >> X[i];
}

void solve() {
	sort(X, X + ( nA + nB ));
	cout << endl;
	vector <int> Union, Intersection;
	for ( int i = 0; i < nA + nB; i++ ) {
		if ( X[i] != X[i - 1] && X[i] == X[i + 1] ) {
			Intersection.push_back(X[i]);
			Union.push_back(X[i]);
		} else if ( X[i] == X[i - 1] ) {
			continue;
		} else {
			Intersection.push_back(X[i]);
		}
	}

	for ( int i = 0; i < Intersection.size(); i++ )
		cout << Intersection[i] << " ";
	cout << endl;

	for ( int i = 0; i < Union.size(); i++ )
		cout << Union[i] << " ";
	cout << endl;
}

int main() {
	int t; cin >> t;
	while ( t-- ) {
		init();
		solve();
	}
}