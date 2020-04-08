#include <bits/stdc++.h>
using namespace std;

int n;
int s[111];

void input () {
	cin >> n;
	for ( int i = 0; i < n; i++ )
		cin >> s[i];
}

void solve () {
	int maxlen = 0;
	int maxsum = 0;

	int curlen = 1;
	int cursum = s[0];

	for ( int i = 1; i<n; i++ ) {
		if ( s[i] > s[i - 1] ) {
			curlen++;
			cursum += s[i];
		} else {
			if ( curlen > maxlen ) {
				maxlen = curlen;
				maxsum = cursum;
			} else if ( curlen == maxlen && cursum > maxsum ) {
				maxlen = curlen;
				maxsum = cursum;
			}

			curlen = 1;
			cursum = s[i];
		}
	}

	if ( curlen > maxlen ) {
		maxlen = curlen;
		maxsum = cursum;
	} else if ( curlen == maxlen && cursum > maxsum ) {
		maxlen = curlen;
		maxsum = cursum;
	}
	cout << maxlen << " " << maxsum << endl;
}

int main () {
	int ntest;
	cin >> ntest;

	for ( int itest = 0; itest < ntest; itest++ ) {
		input ();
		solve ();
	}system ( "pause" );
}