#include<bits/stdc++.h>
#define MAX 11
using namespace std;

int n, num[MAX];
bool chuaxet[MAX];

void display() {
	for ( int vt = 1; vt <= n; vt++ ) // vt: vị trí
		cout << num[vt];
	cout << " ";
}

void Try(int vt) {
	for ( int gt = 1; gt <= n; gt++ ) { //gt: giá trị
		if ( chuaxet[gt] ) {
			num[vt] = gt;
			chuaxet[gt] = false;
			if ( vt == n )
				display();
			else Try(vt + 1);
			chuaxet[gt] = true;
		}
	}
}

int main() {
	int t; cin >> t;
	while ( t-- ) {
		memset(chuaxet, true, MAX);
		cin >> n;
		Try(1);
		cout << endl;
	}
}