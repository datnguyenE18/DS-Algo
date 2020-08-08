#include<bits/stdc++.h>
using namespace std;

//Hàm hoán đổi
void swap ( int &x, int &y ) {
	int temp = x;
	x = y;
	y = temp;
}

string solving ( string arr ) {
	//B1: Duyệt từ đầu lên (trái sang phải), tìm chữ số nhỏ hơn chữ số tiếp theo
	// 34125: ta tìm được số 4
	int index = -1; //ghi nhận index ban đầu
	for ( int i = 0; i < arr.length () - 1; i++ ) {
		if ( arr[i] > arr[i + 1] ) {
			index = i; //ghi nhận index
			break;
		}
	}

	if ( index == -1 ) //Nếu dãy đó đã được sắp xếp tăng dần rồi thì không tìm được số thỏa mãn => trả về -1
		return "-1";

	//B2: duyệt từ cuối xuống (phải sang trái) cho đến index, tìm số lớn nhất nhỏ hơn arr[index]  
	int smallGreatDgt = -1;
	for ( int i = arr.length (); i > index; i-- ) {
		if ( arr[i] < arr[index] ) {
			if ( smallGreatDgt == -1 ) //tìm thấy số nhỏ hơn arr[index] lần đầu tiên => tạm lưu i vào smallGreatDgt, vòng lặp sau sẽ chuyển xuống else if luôn (để tìm số lớn nhất)
				smallGreatDgt = i;
			else if ( arr[i] >= arr[smallGreatDgt] )
				smallGreatDgt = i; // Ghi nhận số lớn nhất nhỏ hơn arr[index]
		}
	}


	if ( index == 0 && arr[smallGreatDgt] == '0' ) 	return "-1";

	if ( smallGreatDgt != -1 ) {
		swap ( arr[index], arr[smallGreatDgt] );
		return arr;
	} 
	return "-1";
}

int main () {
	int T;	string arr;
	cin >> T;
	while ( T-- ) {
		cin >> arr;
		cout << solving ( arr ) << endl;
	}

	system ( "pause" );
	return 0;
}
