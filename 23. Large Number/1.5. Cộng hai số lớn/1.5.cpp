#include<bits/stdc++.h>
using namespace std;

void add(string a, string b) {
	string res = "";
	int s1 = a.size(),
		s2 = b.size();

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int sum = 0, // Tổng tạm
		sur = 0; // số dư, ban đầu là 0
	for ( int i = 0; i < s2; i++ ) {
		sum = ( ( a[i] - '0' ) + ( b[i] - '0' ) + sur );
		sur = sum / 10;
		res.push_back(sum % 10 + '0');
	}

	for ( int i = s2; i < s1; i++ ) {
		sum = ( a[i] - '0' ) + sur;
		sur = sum / 10;
		res.push_back(sum % 10 + '0');
	}

	// Nếu đến cuối cùng vẫn còn dư thì thêm nguyên tổng tạm vào kết quả
	if ( sur )
		res.push_back(sur + '0');
	reverse(res.begin(), res.end());
	cout << res << endl;
}

int main() {
	int t; cin >> t;
	while ( t-- ) {
		string a, b;
		cin >> a;
		cin >> b;
		if ( a.size() > b.size() )
			add(a, b);
		else add(b, a);
	}
}