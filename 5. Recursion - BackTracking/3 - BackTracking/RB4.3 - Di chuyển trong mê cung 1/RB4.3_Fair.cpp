#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int square, // số ô vuông trong ma trận
	mat[MAX][MAX], // mảng 2 chiều lưu ma trận
	count0, //Đếm số cách di chuyển
	i, j;
bool visited[MAX][MAX]; // Lưu trạng thái thăm của ô vuông có tọa độ x, y
string res; // Lưu đường đi

// Khởi tạo ma trận, đếm và visited:
void init() {
	cin >> square;
	count0 = 0;
	for ( i = 1; i <= square; i++ ) {
		for ( j = 1; j <= square; j++ ) {
			visited[i][j] = false;
			cin >> mat[i][j];
		}
	}
}

//Kiểm tra tọa độ (x, y) có thuộc mê cung không và bên dưới / bên phải có đi được không
bool isSafe(int x, int y) {
	if ( x >= 1 && x <= square && y >= 1 && y <= square && !visited[x][y] && mat[x][y] == 1 )
		return true;
	return false;
}

//Đưa ra các đường đi
void showPath(int x, int y) {
	// Trường hợp dừng: Nếu đã đến đích thi in ra đường đi hiện tại
	if ( x == square && y == square ) {
		visited[x][y] = true; // đã thăm ô có tọa độ x, y
		count0++;
		cout << res << " ";
	}

	//Nếu x, y vẫn thuộc mê cung:
	if ( isSafe(x, y) ) {
		visited[x][y] == true; //ghi nhận ô đã thăm đi qua ô này

		//Nếu bên dưới có thể đi được:
		if ( isSafe(x + 1, y) ) {
			res += 'D';
			showPath(x + 1, y);
		}

		//Nếu bên phải có thể đi được:
		if ( isSafe(x, y + 1) ) {
			res += 'R';
			showPath(x, y + 1);
		}

		//Nếu không còn đường để đi:
		visited[x][y] = false; // Trả lại giá trị quay lui cho ô trước đó để quay lại xét trường hợp khác
		if ( res.length() != 0 ) //Xóa ô vừa mới đi đi vì đứng ở ô này không đi được tới đích, xóa đi để xét trường hợp khác từ ô trước đó
			res.erase(res.length() - 1);
	}
}

int main() {
	int t; cin >> t;
	while ( t-- ) {
		init();
		showPath(1, 1);
		if ( count0 == 0 ) cout << "-1"; //Nếu không có cách đi nào thì in ra '-1'
		cout << endl;
	}
}