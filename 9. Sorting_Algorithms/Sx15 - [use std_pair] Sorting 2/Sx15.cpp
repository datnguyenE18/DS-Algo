// Sắp xếp + tham lam
#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 1;

int n, X;
pair <int, int> a[maxN];

/*
cmp có thứ tự sắp xếp:
	- đầu tiên là sắp xếp thep |X - a[i]|
	- Nếu 2 trị tuyệt đối bằng nhau thì ưu tiền vị trí xuất hiện.
*/
bool cmp(pair<int, int> a, pair<int, int> b) {
	if ( abs(a.first - X) == abs(b.first - X) ) return a.second < b.second;
	else  return( abs(a.first - X) < abs(b.first - X) );
}

void init() {
	cin >> n >> X;
	for ( int i = 0; i < n; i++ ) {
		cin >> a[i].first;
		a[i].second = i;
	}
}

void solve() {
	sort(a, a + n, cmp);

	for ( int i = 0; i < n; i++ )
		cout << a[i].first << " ";
	cout << endl;
}

int main() {
	int t; cin >> t;
	while ( t-- ) {
		init();
		solve();
	}
}