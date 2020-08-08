#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int ver,
	adj_mat[MAX][MAX], // Mảng 2 chiều lưu ma trận kề trọng số
	st, // Điểm cố định (điểm ban đầu)
	d[MAX], // độ dài đường đi tới điểm cố định
	pre[MAX]; // Lưu vết
bool included[MAX]; // Đánh dấu những đỉnh đã nằm trên đường đi

void read_adj_mat() {
	ifstream FileIn;
	FileIn.open("graph.dat", ios_base::in);

	FileIn >> ver;
	for ( int i = 1; i <= ver; i++ )
		for ( int j = 1; j <= ver; j++ )
			FileIn >> adj_mat[i][j];

	FileIn.close();
	cout << "Read adjacency matrix from a file: \n\n";
}

void dis_adj_mat() {
	for ( int i = 1; i <= ver; i++ ) {
		for ( int j = 1; j <= ver; j++ ) {
			if ( adj_mat[i][j] == 999 )
				cout << "inf" << "  ";
			else cout << " " << adj_mat[i][j] << "   ";
		} cout << "\n\n";
	}
}

void init() {
	cout << "The Starting Point: "; cin >> st; // Nhập điểm cố định
	pre[st] = 0; // trước đỉnh cố định ban đầu không có đỉnh nào cả

	for ( int i = 1; i <= ver; i++ ) {
		d[i] = adj_mat[st][i]; // độ dài ban đầu của đường đi từ đỉnh cố định đến các đỉnh khác
		included[i] = false; // Ban đầu chưa đỉnh nào nằm trên đường đi
	}
}

// Tìm đỉnh tiếp theo có đường đi từ đỉnh cố định tới chúng nhỏ nhất
int minDist() {
	int min = INT_MAX; // độ dài đường đi nhỏ nhất từ đỉnh đang xét tới đỉnh cố định (ban đầu tạm cho bằng số lớn nhất có thể, tương đương với ∞)
	int index; // lưu đỉnh cần tìm

	for ( int i = 1; i <= ver; i++ ) // Quét qua 1 loạt các đỉnh trong đồ thị để tìm đỉnh tiếp theo có đường đi ngắn nhất tới Đỉnh cố định
		if ( included[i] == false && d[i] < min ) { // Nếu đỉnh đó chưa có trong cây khung (included[i] == false), và đỉnh đó tồn tại đường đi tới đỉnh cố định (d[i] < min - tức là d[i] khác ∞)... 
			min = d[i]; //... thì lưu giá trị đó tạm thời là độ dài đường đi nhỏ nhất...
			index = i; //... và lưu đỉnh đó tạm thời là đỉnh có đường đi ngắn nhất tới Đỉnh cố định
		}
	return index; // cuối cùng tìm được đỉnh tiếp theo có đường đi ngắn nhất tới ĐCĐ
}

void dijkstra() {
	// Tìm đường đi ngắn nhất cho tất cả các đỉnh
	for ( int i = 1; i <= ver - 1; i++ ) { // Xét các đỉnh của đồ thị (trừ Đỉnh cố định) để cập nhật lại độ dài đường đi tới điểm cố định sau khi...
		int u = minDist(); // ... tìm được đỉnh tiếp theo có đường đi tới điểm cố định ngắn nhất
		included[u] = true; // thêm đỉnh đó vào tập đường đi
		cout << "\n+ Vertex " << u << " : ";
		// Quét qua tất cả các đỉnh để cập nhật lại độ dài đường đi và pre[...] sau khi tìm được đỉnh tiếp theo (u) bên trên
		for ( int j = 1; j <= ver; j++ ) {
			if ( included[j] == false && adj_mat[u][j] && d[u] != INT_MAX && d[u] + adj_mat[u][j] < d[j] ) { // Nếu đỉnh đó chưa nằm trên đường đi và có độ dài đường đi ngắn nhất tới ĐCĐ nhỏ hơn độ dài ban đầu thì mới cập nhật
				d[j] = d[u] + adj_mat[u][j];
				pre[j] = u;
			}
			cout << "(" << d[j] << ":" << pre[j] << ")";
		}
	}
	cout << "\n\n";
	for ( int i = 1; i <= ver; i++ ) {
		if ( pre[i] == 0 && i != st )
			cout << "- pre[" << i << "]: " << st << endl;
		else cout << "- pre[" << i << "]: " << pre[i] << endl;
	}
	cout << endl;
	for ( int i = 1; i <= ver; i++ ) {
		cout << "The distance from " << st << " to " << i << " is	: " << d[i] << endl;
	}
}

int main() {
	read_adj_mat();
	dis_adj_mat();
	init();
	dijkstra();
}

/*
Read adjacency matrix from a file:

 0    1   inf  inf  inf  inf

inf   0    5    2   inf   7

inf  inf   0   inf  inf   1

 2   inf   1    0    4   inf

inf  inf  inf   3    0   inf

inf  inf  inf  inf   1    0

The Starting Point: 2

+ Vertex 2 : (999:0)(0:0)(5:0)(2:0)(999:0)(7:0)
+ Vertex 4 : (4:4)(0:0)(3:4)(2:0)(6:4)(7:0)
+ Vertex 3 : (4:4)(0:0)(3:4)(2:0)(6:4)(4:3)
+ Vertex 1 : (4:4)(0:0)(3:4)(2:0)(6:4)(4:3)
+ Vertex 6 : (4:4)(0:0)(3:4)(2:0)(5:6)(4:3)

- pre[1]: 4
- pre[2]: 0
- pre[3]: 4
- pre[4]: 2
- pre[5]: 6
- pre[6]: 3

The distance from 2 to 1 is     : 4
The distance from 2 to 2 is     : 0
The distance from 2 to 3 is     : 3
The distance from 2 to 4 is     : 2
The distance from 2 to 5 is     : 5
The distance from 2 to 6 is     : 4
*/