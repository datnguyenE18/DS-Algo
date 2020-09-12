#include<bits/stdc++.h>
using namespace std;

bool bigger(string a, string b) {
	int s1 = a.length(),
		s2 = b.length();

	if ( s1 > s2 ) return true;
	else if ( s1 < s2 ) return false;
	else {
		for ( int i = 0; i < s1; i++ ) {
			if ( a[i] < b[i] ) return false;
			else if ( a[i] > b[i] ) return true;
		}
	} return true;
}

void sub(string a, string b) {
	string res = ""; // Xâu lưu kết quả

	// Độ dài xâu a và b:
	int s1 = a.length(),
		s2 = b.length();

	// Đảo ngược 2 xâu (vì phải thực hiện trừ từ dưới lên):
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int carry = 0, // Số nhớ ban đầu = 0
		sub = 0;
	for ( int i = 0; i < s2; i++ ) { // lặp theo độ dài số nhỏ hơn
		sub = ( ( a[i] - '0' ) - ( b[i] - '0' ) - carry );
		if ( sub < 0 ) { // nếu hiệu âm (a[i] < b[i])
			sub += 10; //Thì phải tăng tạm số bị trừ lên 10, ở đây ta tăng lên ở hiệu
			carry = 1; // Khi đó thì số dự là 1
		} else carry = 0; // Nếu trừ không âm thì số nhớ vẫn = 0
		res.push_back(sub + '0'); // thêm hiệu đó vào kết quá
	}

	// Trường hợp Số bị trừ dài hơn số trừ và khi số trừ hết rồi số bị trừ vẫn còn
	// thì lấy phần tử tiếp ở số bị trừ, trừ đi 0 và trừ đi số nhớ trước đó (nếu có)
	// Tạm hiểu 12345 - 11 = 12345 - 00011
	for ( int i = s2; i < s1; i++ ) {
		sub = ( a[i] - '0' ) - carry;
		if ( sub < 0 ) {
			sub += 10;
			carry = 1;
		} else carry = 0;
		res.push_back(sub + '0');
	}

	// Đảo ngược res lại để có kết quả:
	reverse(res.begin(), res.end());
	cout << res << endl;
}

int main() {
	int t; cin >> t;
	string a, b;
	while ( t-- ) {
		cin >> a;
		cin >> b;

		if ( bigger(a, b) ) // Nếu a >= b
			sub(a, b);
		else // Nếu a < b
			sub(b, a);
	}

}