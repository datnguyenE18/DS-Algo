#include<iostream>
#include<vector>
#include<algorithm> //std::sort
using namespace std;

void Xuat ( vector<double> arr, int n ) {
	for ( int i = 0; i < n; i++ ) cout << arr[i] << " ";
	cout << endl;
}

bool comp ( double i, double j ) { return ( i > j ); }

int main () {
	vector<double> arr;
	int n;

	cout << "Nhap n: "; cin >> n;
	for ( int i = 0; i < n; i++ ) {
		double temp; cin >> temp;
		arr.push_back ( temp );
	}

	cout << "Cac phan tu da nhap: "; Xuat ( arr, n );

	//SẮP XẾP TĂNG DẦN:
	sort ( arr.begin (), arr.end () );
	cout << "Tang dan: "; Xuat ( arr, n );

	//SẮP XẾP GIẢM DẦN:
	/*comp ở đây là tham số truyền vào cho con trỏ hàm của hàm std::sort()
	Nếu không có comp thì nó sẽ mặc định sắp xếp tăng dần, hàm sẽ dùng toán tử <= đã định nghĩa, giả sử muốn sắp xếp giảm dần hay muốn sắp xếp theo
	ý mình thì phải tự viết hàm so sánh sau đó truyền vào cho con trỏ hàm của hàm std::sort().*/
	sort ( arr.begin (), arr.end (), comp );
	cout << "Giam dan: "; Xuat ( arr, n );

	system ( "pause" );
}