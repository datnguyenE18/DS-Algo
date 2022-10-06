#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int t, // Số bộ test
n, //quân số
k, // số chiến sĩ phải tập
aft[MAX]; //lưu quân sau khi thay đổi
set <int> bef; // quân ban đầu, vì mỗi quân là riêng biệt, duy nhất nền ta dùng Set

void input () {
	for ( int i = 1; i <= k; i++ ) {
		cin >> aft[i];
		bef.insert ( aft[i] );
	}
}

void next_combin () {
	int i = k;
	while ( i >= 1 && aft[i] == n - k + i ) i--;

	if ( i > 0 ) {
		aft[i]++;
		for ( int j = i + 1; j <= k; j++ )
			aft[j] = aft[i] + j - i;
	}
}

void result () {
	int dem = 0;
	for ( int i = 1; i <= k; i++ ) {
		if ( bef.find ( aft[i] ) == bef.end () )
			dem++;
	}
	if ( dem != 0 ) cout << dem << endl;
	else cout << k << endl;
}

int main () {
	cin >> t;
	while ( t-- ) {
		cin >> n >> k;
		bef.clear (); //Làm sạch Set để tránh cấu hình từ test trước đó
		input ();
		next_combin ();
		result ();
	} system ( "pause" );
}