#include<bits/stdc++.h>
using namespace std;
#define MAX 1001

int ver, adj_mat[MAX][MAX];

void reader() {
	ifstream FileIn;
	FileIn.open("graph.dat", ios_base::in);
	FileIn >> ver;

	for ( int i = 1; i <= ver; i++ ) {
		for ( int j = 1; j <= ver; j++ )
			FileIn >> adj_mat[i][j];
	}

	FileIn.close();
	cout << "Read adjacency matrix from a file: \n\n";
}

void dis_adj_mat() {
	for ( int i = 1; i <= ver; i++ ) {
		for ( int j = 1; j <= ver; j++ )
			cout << adj_mat[i][j] << " ";
		cout << endl;
	} cout << endl;
}

void Euler_Cycle(int node) {
	stack<int> stack0, CE; // Tạo ngăn xếp và CE rỗng
	stack0.push(node); // Đưa đỉnh đầu tiên vào ngăn xếp

	while ( !stack0.empty() ) {
		node = stack0.top(); // Lấy đỉnh đầu tiên trong ngăn xếp stack0
		for ( int i = 1; i <= ver; i++ ) { // Quét các cột của hàng 'node' (quét các đỉnh kề với đỉnh node)
			if ( adj_mat[node][i] ) { // Tìm được đỉnh kề gần nhất thì
				stack0.push(i); // Thêm đỉnh đó vào ngăn xếp stack0
				adj_mat[node][i] = adj_mat[i][node] = 0; // Xóa cạnh nối 2 đỉnh đó đi
				break; // thoát vòng lặp ra ngoài để tiếp tục lấy đỉnh trong ngăn xếp stack0
			} else if ( i == ver ) { // Nếu đã quết đến cuối => tức là Danh sách kề đã rỗng
				CE.push(node); // Thì thêm đỉnh đó vào ngăn xếp CE
				stack0.pop(); // Rồi xóa đỉnh đó khỏi ngăn xếp stack0
			}
		}
	}

	// In ra chu trình:
	cout << "\nEuler Cycle: ";
	while ( !CE.empty() ) {
		cout << CE.top() << " ";
		CE.pop();
	}
}

int main() {
	int node;
	reader();
	dis_adj_mat();
	cout << "First point = ";  cin >> node;
	Euler_Cycle(node);
}
/*
Read adjacency matrix from a file:

0 1 0 0 0 1 0 0 0 0 0 0 0
1 0 1 0 1 1 0 0 0 0 0 0 0
0 1 0 1 1 0 0 0 0 0 1 0 0
0 0 1 0 0 0 1 1 0 0 1 0 0
0 1 1 0 0 1 1 0 0 0 0 0 0
1 1 0 0 1 0 1 0 0 0 0 0 0
0 0 0 1 1 1 0 1 0 0 0 0 0
0 0 0 1 0 0 1 0 1 1 0 0 0
0 0 0 0 0 0 0 1 0 1 0 1 1
0 0 0 0 0 0 0 1 1 0 1 1 0
0 0 1 1 0 0 0 0 0 1 0 1 0
0 0 0 0 0 0 0 0 1 1 1 0 1
0 0 0 0 0 0 0 0 1 0 0 1 0

First point = 1

Euler Cycle: 1 2 3 4 7 5 2 6 5 3 11 4 8 9 10 11 12 9 13 12 10 8 7 6 1
*/