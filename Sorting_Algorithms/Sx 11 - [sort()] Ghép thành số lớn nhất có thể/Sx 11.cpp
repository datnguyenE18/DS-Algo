#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// So sánh hai xâu
int myCompare ( string X, string Y ) {
	string XY = X.append ( Y ); // nối X với Y
	string YX = Y.append ( X ); //nối Y với X

	//kiểm tra xem số nào trong 2 số được tạo thành số nào lớn hơn
	if ( XY > YX ) return 1;
	return 0;
	//có thể viết:| if ( XY.compare ( YX ) > 0 ) return 1;
	//			  |	return 0;

	//Hoặc có thể viết gọn là:     return XY.compare(YX) > 0 ? 1: 0; 
}

// Hàm sắp xếp các phần tử của vector
void Largest ( vector<string> arr ) {
	sort ( arr.begin (), arr.end (), myCompare );
	/* myCompare là tham số truyền vào cho con trỏ hàm của hàm std::sort(),
	+) Nếu không có myCompare thì hàm sẽ dùng toán tử <= đã định nghĩa
	nó sẽ mặc định sắp xếp tăng dần.
	+) Muốn sắp xếp theo ý mình thì phải tự viết hàm so sánh sau đó truyền 
	vào cho con trỏ hàm của hàm std::sort(). Ở đây đã viết hàm so sánh myCompare,
	hàm sort sẽ hiểu là ghép 2 số sao cho chọn số ghép lớn hơn*/

	//In ra số lớn nhất:
	for ( int i = 0; i < arr.size (); i++ ) {
		cout << arr[i];
	}
	cout << endl;
}

int main () {
	int T, n;
	string str;
	vector<string>arr;
	cin >> T;
	while ( T-- ) {
		cin >> n;
		for ( int i = 0; i < n; i++ ) {
			cin >> str;
			arr.push_back ( str ); //thêm phần tử str vừa nhập vào vị trí sau cùng của vector
		}
		Largest ( arr );
	}

	system ( "pause" );
	return 0;
}