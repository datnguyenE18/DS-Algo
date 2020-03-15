#include <bits/stdc++.h>
using namespace std;

string formatString ( string input ) {
	int n = input.length ();

	// Xóa khoảng trắng đầu 
	while ( input[0] == ' ' ) {
		input.erase ( input.begin () );
		n--;
	}

	// Xóa khoảng trắng thừa vùng giữa 
	for ( int i = 0; i < n; i++ ) {
		while ( input[i] == ' ' && input[i + 1] == ' ' ) {
			input.erase ( input.begin () + i + 1 );
			n--;
		}
	}

	// Xóa khoảng trắng cuối
	while ( input[n - 1] == ' ' )
		input.erase ( input.begin () + n - 1 );

	// Viết hoa mỗi chữ cái đầu:
	//B1: Chuyển cả chuỗi về chữ thường
	transform ( input.begin (), input.end (), input.begin (), ::tolower );
	
	//B2: Viết hoa đầu mỗi chữ:
	//Viết hoa ký tự đầu của từ đầu tiên:
	if ( input[0] >= 'a' && input[0] <= 'z' ) {
		input[0] -= 32; //Hoặc có thể: input[0] -= ('a' - 'A'); nếu không nhớ
	}

	// Viết hoa ký tự đầu tiên ở mỗi từ ở khoảng giữa
	for ( int i = 0; i < input.length () - 1; i++ ) {
		if ( input[i] == ' ' && input[i + 1] != ' ' ) {
			if ( input[i + 1] >= 97 && input[i + 1] <= 122 ) { //Hoặc có thể : if ( input[0] >= 'a' && input[0] <= 'z' ) nếu không nhớ
				input[i + 1] -= 32;
			}
		}
	}
	return input;
}



int main () {
	string input = "  nGuyen conG Linh ";
	cout << formatString ( input ) << endl;
	system ( "pause" );
}