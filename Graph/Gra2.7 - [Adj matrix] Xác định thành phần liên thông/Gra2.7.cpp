#include<bits/stdc++.h>
using namespace std;

int ver, //Số đỉnh 
i, j,
adj_mat[1001][1001]; //Mảng 2 chiều lưu ma trận kề
bool visited[1001]; //mảng 2 chiều lưu hiện trạng của đỉnh (đã thăm/ chưa thăm)

//Khởi tạo mảng Reinit (Tất cả các đỉnh đều chưa thăm):
void Reinit() {
	for ( i = 1; i <= ver; i++ )
		visited[i] = false;
}

//Đọc ma trận kề từ file:
void reader() {
	ifstream FileIn;
	FileIn.open("graph.dat", ios_base::in);

	FileIn >> ver;
	for ( i = 1; i <= ver; i++ ) {
		for ( int j = 1; j <= ver; j++ )
			FileIn >> adj_mat[i][j];
	}
	FileIn.close();
	cout << "Read adjacency matrix from a file : \n\n";
}

//In ra ma trận vừa đọc:
void dis_adj_mat() {
	for ( i = 1; i <= ver; i++ ) {
		for ( j = 1; j <= ver; j++ )
			cout << adj_mat[i][j] << " ";
		cout << endl;
	} cout << "\n";
}

//DFS sử dụng Stack
void DFS(int node) {
	stack<int>stack0;
	stack0.push(node);
	visited[node] = true;
	cout << node << " ";

	while ( !stack0.empty() ) {
		int s = stack0.top();
		stack0.pop();
		for ( int i = 1; i <= ver; i++ ) {
			if ( adj_mat[s][i] == 1 && visited[i] == false ) {
				cout << i << " ";
				visited[i] = true;
				stack0.push(s);
				stack0.push(i);
				break;
			}
		}
	} cout << endl;
}

//BFS sử dụng Queue
void BFS(int node) {
	queue<int> queue0;
	queue0.push(node);
	visited[node] = true;

	while ( !queue0.empty() ) {
		int s = queue0.front();
		cout << s << " ";
		queue0.pop();
		for ( int i = 1; i <= ver; i++ ) {
			if ( adj_mat[s][i] == 1 && visited[i] == false ) {
				queue0.push(i);
				visited[i] = true;
			}
		}
	} cout << "\n";
}

//Xác định thành phần liên thông:
void conComp() {
	int count = 0;
	for ( int i = 1; i <= ver; i++ ) {
		if ( visited[i] == false ) {
			count++;
			cout << " * Connected component " << count << ": ";
			//DFS(i);
			BFS(i);
		}
	}
	cout << "=> Number of connected components: " << count << "\n";
}

int main() {
	reader();
	dis_adj_mat();
	Reinit();
	conComp();
}

/*
Read adjacency matrix from a file :

0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 1
1 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 1 0 1 0 1 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0 1 0 1 0 0 0 0 1 0 0 0 0
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 1 0 0 0
0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0
0 0 1 1 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1
0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1
0 0 0 1 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 1 1
1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0
1 1 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 1 0
0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 1 0 1 0 1
1 0 0 0 0 0 0 0 0 0 0 0 1 1 0 1 0 0 1 0

 * Connected component 1: 1 2 17 18 20 6 7 8 9 12 16 19 13 14 11 3 4 15 10 5
=> Number of connected components is: 1
*/