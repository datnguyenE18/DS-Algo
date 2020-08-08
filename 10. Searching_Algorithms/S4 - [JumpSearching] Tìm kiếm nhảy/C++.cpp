#include <bits/stdc++.h> 
using namespace std;

int jumpSearch ( int arr[], int x, int n ) {
	// Tôi xác định giá trị nhảy: 
	int step = sqrt ( n );
	int prev = 0; // Sử dụng một biến prev để lưu vị trí bắt đầu
	while ( arr[min ( step, n ) - 1] < x ) { // Kiểm tra vị trí ngay trước vị trí step so với x, nếu vẫn nhỏ hơn x thì nhảy tiếp. Min để tránh trường hợp step nhảy quá n thì phải lùi lại n để kéo prev lên đánh dấu và so sánh 
		prev = step; //Nhảy đến đâu thì kéo theo prev tăng theo giá trị của step đến đó
		step += sqrt ( n ); //tiếp tục nhảy
		if ( prev >= n ) // Nếu đã nhảy hết mà prev đã >= n vẫn không tìm ra thì dừng
			return -1;
	} // Khi đã tìm được số lớn hơn x thì dừng while. Lúc này prev và step giữ nguyên vị trí (giá trị) vì không thực hiện lệnh nhảy nữa
	// Khi này đã xác định được khoảng chứa x là [prev, step]

	// Tìm kiếm tuyến tính trong khoảng [prev, step] để tìm x:
	while ( arr[prev] < x ) {
		prev++;
		// nếu chạy đến cuối khối hoặc cuối mảng mà vẫn không tìm thấy giá trị x thì dừng
		if ( prev == min ( step, n ) ) //Dùng Min vì có thể step trước đó đã nhảy qua n
			return -1;
	}
	// Nếu tìm thấy x thì dừng và trả về giá trị:
	if ( arr[prev] == x ) return prev;
	return -1; // Đề phòng x ko tồn tại nhưng prev đã nhảy đến giá trị lớn hơn x => sẽ thoát khỏi vòng while (cũng không thỏa mãn if) nên sẽ in luôn ra prev là KQ sai 
}

int main () {
	int *arr, n, x;
	cout << "So phan tu mang: "; cin >> n;
	arr = new int[n];
	cout << "Nhap mang: ";
	for ( int i = 0; i < n; i++ ) cin >> arr[i];
	cout << "So can tim: "; cin >> x;
	if ( jumpSearch ( arr, x, n ) + 1 ) {
		cout << "So can tim tai vi tri: " << jumpSearch ( arr, x, n ) << endl;
	} else cout << "Khong tim thay so can tim!" << endl;

	system ( "pause" );
	return 0;
}

