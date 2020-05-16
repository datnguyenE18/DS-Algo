#include<bits/stdc++.h>
using namespace std;
#define MAX 1001

int N,  // Số ô vuông
	mat[MAX][MAX]; // ma trận 2 chiều lưu 
vector<string> vt;
string ans;

void init() {
	cin >> N;
	for ( int i = 1; i <= N; i++ ) {
		for ( int j = 1; j <= N; j++ )
			cin >> mat[i][j];
	}
}

void Try(int x, int y) {
	if ( mat[1][1] == 0 || mat[N][N] == 0 )
		return;

	if ( x == N && y == N )
		vt.push_back(ans);

	if ( mat[x + 1][y] == 1 && x != N ) {
		ans += 'D';
		Try(x + 1, y);
		ans.erase(ans.length() - 1);
	}

	if ( mat[x][y + 1] == 1 && y != N ) {
		ans += 'R';
		Try(x, y + 1);
		ans.erase(ans.length() - 1);
	}
}

void showPath() {
	Try(1, 1);
	if ( vt.empty() ) cout << "-1" << endl;
	else {
		for ( int i = 0; i < vt.size(); i++ )
			cout << vt[i] << " ";
		cout << endl;
	}
}

int main() {
	int t; cin >> t;
	while ( t-- ) {
		init();
		showPath();
	}
}