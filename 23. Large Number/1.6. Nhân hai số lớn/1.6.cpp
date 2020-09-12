#include<bits/stdc++.h> 
using namespace std;

string MultiplyStrings(string s1, string s2) {
	int len1 = s1.size(),
		len2 = s2.size();

	if ( len1 == 0 || len2 == 0 ) // Nếu một trong hai số = 0 thì kết quả = 0 
		return "0";

	vector<int> result(len1 + len2, 0); // Kết quả lưu trong vector với thứ tự ngược

	int i_n1 = 0,
		i_n2 = 0;

	for ( int i = len1 - 1; i >= 0; i-- ) { //Duyệt từ phải qua trái s1
		int carry = 0, // số dư ban đầu = 0
			n1 = s1[i] - '0',
			i_n2 = 0;

		// Duyệt từ phải qua trái s2              
		for ( int j = len2 - 1; j >= 0; j-- ) {
			int n2 = s2[j] - '0',
				sum = n1 * n2 + result[i_n1 + i_n2] + carry; // Nhân hai số và lưu vào vị trí hiện tại
			carry = sum / 10; //luu lai so nho cho lan lap tiep              
			result[i_n1 + i_n2] = sum % 10; //luu chu so vao vi tri  
			i_n2++;
		}
		if ( carry > 0 ) // Nếu vẫn còn dư
			result[i_n1 + i_n2] += carry;
		i_n1++; //Chuyển đến số tiếp theo của s1
	}

	// Loại bỏ các số 0 bên phải
	int i = result.size() - 1;
	while ( i >= 0 && result[i] == 0 )
		i--;
	if ( i == -1 )
		return "0";

	string s = "";
	while ( i >= 0 ) {
		char x = '0' + result[i];
		s.append(1, x); i--;
	}

	return s;
}

int main() {
	int t; cin >> t;
	string str1, str2;

	while ( t-- ) {
		cin >> str1; cin >> str2;
		if ( ( str1.at(0) == '-' || str2.at(0) == '-' ) &&
			( str1.at(0) != '-' || str2.at(0) != '-' ) )
			cout << "-";
		if ( str1.at(0) == '-' && str2.at(0) != '-' ) {
			str1 = str1.substr(1);
		} else if ( str1.at(0) != '-' && str2.at(0) == '-' ) {
			str2 = str2.substr(1);
		} else if ( str1.at(0) == '-' && str2.at(0) == '-' ) {
			str1 = str1.substr(1);
			str2 = str2.substr(1);
		}
		cout << MultiplyStrings(str1, str2) << endl;
	}
}
