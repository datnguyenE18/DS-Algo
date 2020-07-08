#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int ver, // Số đỉnh của  
	edg = 0, // Số cạnh của cây khung (ban đầu = 0)
	MSTweight = 0, // Độ dài cây khung nhỏ nhất 
	adj_mat[MAX][MAX], // Ma trận kề của đồ thị trọng số
	node; // Đỉnh bắt đầu
bool included[MAX * MAX]; // Lưu những đỉnh đã ở trong tập cây khung chưa

void read_adj_mat() {
	ifstream FileIn;
	FileIn.open("graph.dat", ios_base::in);

	FileIn >> ver;
	for ( int i = 1; i <= ver; i++ ) {
		for ( int j = 1; j <= ver; j++ ) {
			FileIn >> adj_mat[i][j];
		}
	}
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

void prim(int start) {
	memset(included, false, sizeof(included)); // ban đầu chưa có đỉnh nào trong tập cây khung
	included[start] = true; // Đỉnh đầu tiên trong tập cây khung
	while ( edg < ver - 1 ) { // Nếu số cạnh đã duyệt = Số đỉnh - 1 thì dừng
		int min = 999, // giá trị trọng số nhỏ nhất cạnh nối 2 đỉnh đang xét (ban đầu bằng 999, tương đương với ∞)
			x = 0, y = 0; // để lưu cạnh (2 đỉnh) đã xử lý trong vòng for ra ngoài
		for ( int i = 1; i <= ver; i++ ) { // Quét các đỉnh trên đồ thị
			if ( included[i] ) { // Xét các đỉnh đã ở trong tập cây khung  
				for ( int j = 1; j <= ver; j++ ) // Kiểm tra các đỉnh xung quanh nó
					if ( !included[j] /*&& adj_mat[i][j]*/ ) { // Nếu đỉnh xung quanh đó chưa xét
						if ( adj_mat[i][j] < min ) { // thì xem đâu là đỉnh có cạnh nối với nó có trọng số nhỏ nhất 
							min = adj_mat[i][j]; // Lưu tạm trọng số nhỏ hơn đó vao min

							//Lưu tạm cạnh có trọng số nhỏ nhất đó :
							x = i;
							y = j;
						}
					}
			}
		}
		// đến cuối cùng, sau vòng for ta có cạnh có trọng số nhỏ nhất:
		MSTweight += adj_mat[x][y];
		cout << x << " - " << y << "	: " << adj_mat[x][y] << endl;
		included[y] = true;
		edg++;
	}
	cout << "\n=> MSTweight : " << MSTweight << endl;
}

int main() {
	read_adj_mat();
	dis_adj_mat();
	cout << "Pointing Start = "; cin >> node;
	prim(node);
}

/*
Read adjacency matrix from a file:

inf   2    1    3   inf  inf  inf  inf  inf  inf  inf  inf  inf

 2   inf   2   inf  inf   5    5   inf  inf  inf  inf  inf  inf

 1    2   inf   4   inf   5   inf  inf  inf  inf  inf  inf  inf

 3   inf   4   inf   5    5   inf  inf  inf  inf  inf  inf  inf

inf  inf  inf   5   inf   6   inf  inf  inf   6   inf  inf  inf

inf   5    5    5    6   inf   6    6    6    6   inf  inf  inf

inf   5   inf  inf  inf   6   inf   6   inf  inf  inf  inf  inf

inf  inf  inf  inf  inf   6    6   inf   7   inf  inf   7    7

inf  inf  inf  inf  inf   6   inf   7   inf   7    7   inf  inf

inf  inf  inf  inf   6    6   inf  inf   7   inf   7    7   inf

inf  inf  inf  inf  inf  inf  inf  inf   7    7   inf   8   inf

inf  inf  inf  inf  inf  inf  inf   7   inf   7    8   inf   8

inf  inf  inf  inf  inf  inf  inf   7   inf  inf  inf   8   inf

Pointing Start = 1
1 - 3   : 1
1 - 2   : 2
1 - 4   : 3
2 - 6   : 5
2 - 7   : 5
4 - 5   : 5
5 - 10  : 6
6 - 8   : 6
6 - 9   : 6
8 - 12  : 7
8 - 13  : 7
9 - 11  : 7

=> MSTweight : 60
*/