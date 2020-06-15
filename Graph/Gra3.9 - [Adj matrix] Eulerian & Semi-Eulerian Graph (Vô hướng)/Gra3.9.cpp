﻿#include<bits/stdc++.h>
using namespace std;
#define MAX 1001

int ver, adj_mat[MAX][MAX], count0, degree[MAX];
bool visited[MAX], isEuler;

// Đọc ma trận từ file "graph.dat"
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

// In ra ma trận vừa đọc:
void dis_adj_mat() {
	for ( int i = 1; i <= ver; i++ ) {
		for ( int j = 1; j <= ver; j++ )
			cout << adj_mat[i][j] << " ";
		cout << endl;
	} cout << endl;
}

// DFS:
int DFS(int node) {
	stack <int> stack0;
	stack0.push(node);
	visited[node] = true;
	count0 = 1;

	while ( !stack0.empty() ) {
		node = stack0.top();
		stack0.pop();

		for ( int i = 1; i <= ver; i++ ) {
			if ( adj_mat[node][i] != 0 && visited[i] == false ) {
				count0++;
				visited[i] = true;
				stack0.push(node);
				stack0.push(i);
				break;
			}
		}
	}
	return count0;
}

// BFS:
int BFS(int node) {
	queue<int> queue0;
	int count0 = 1;
	queue0.push(node);
	visited[node] = true;

	while ( !queue0.empty() ) {
		node = queue0.front();
		queue0.pop();

		for ( int t = 1; t <= ver; t++ ) {
			if ( visited[t] == false && adj_mat[node][t] != 0 ) {
				count0++;
				queue0.push(t);
				visited[t] = true;
			}
		}
	}
	return count0;
}

// Kiểm tra ma trận vô hướng có là Eulerian/ Semi-Eulerian không:
bool check() {
	for ( int i = 1; i <= ver; i++ ) visited[i] = false;
	if ( /*BFS(1)*/ DFS(1) != ver ) return false;
	count0 = 0;
	for ( int i = 1; i <= ver; i++ ) {
		int sum = 0;
		for ( int j = 1; j <= ver; j++ ) {
			if ( adj_mat[i][j] != 0 )
				sum++;
		}
		degree[i] = sum;
		if ( sum % 2 != 0 ) count0++;
	}
	if ( count0 == 0 ) {
		isEuler = true;
		return true;
	} else if ( count0 == 2 ) {
		cout << "This is a Semi-Eulerian Graph\n";
		isEuler = false;
		return true;
	}
	return false;
}

void Euler(int node) {
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
	cout << "\nEuler: ";
	while ( !CE.empty() ) {
		cout << CE.top() << " ";
		CE.pop();
	}
}

int main() {
	int node;
	reader();
	dis_adj_mat();
	bool temp = check();
	if ( isEuler ) {
		cout << "This is an Eulerian Graph\n";
		if ( temp ) {
			cout << "First point = ";  cin >> node;
			Euler(node);
			return 0;
		}
	} else {
		while ( temp ) {
			cout << "First point = ";  cin >> node;
			if ( degree[node] % 2 == 0 ) {
				cout << "Please start from an odd-degree vertex.\n";
				continue;
			}
			Euler(node);
			return 0;
		}
	}
	cout << "The graph isn't an Eulerian / Semi-Eulerian Graph";
}

/*
Read adjacency matrix from a file:

0 1 0 0 1 1 0 0 0 0 0 0 0
1 0 1 0 1 1 0 0 0 0 0 0 0
0 1 0 1 1 0 0 0 0 0 1 0 0
0 0 1 0 1 0 1 1 0 1 1 0 0
1 1 1 1 0 1 1 0 0 0 0 0 0
1 1 0 0 1 0 1 0 0 0 0 0 0
0 0 0 1 1 1 0 1 0 0 0 0 0
0 0 0 1 0 0 1 0 1 1 0 0 0
0 0 0 0 0 0 0 1 0 1 0 1 1
0 0 0 1 0 0 0 1 1 0 1 1 1
0 0 1 1 0 0 0 0 0 1 0 1 0
0 0 0 0 0 0 0 0 1 1 1 0 1
0 0 0 0 0 0 0 0 1 1 0 1 0

This is a Semi-Euler Graph
First point = 5
Please start from an odd-degree vertex.
First point = 13

Euler: 13 9 8 4 3 2 1 5 2 6 5 3 11 4 5 7 4 10 9 12 10 11 12 13 10 8 7 6 1
*/

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

This is an Euler Graph
First point = 5

Euler: 5 2 1 6 2 3 4 7 5 3 11 4 8 9 10 11 12 9 13 12 10 8 7 6 5
*/

/*
Read adjacency matrix from a file:

0 2 0 2 0 0 0 0 0 0
2 0 1 1 0 0 0 0 0 0
0 1 0 1 1 0 0 0 0 0
2 1 1 0 2 0 0 0 0 0
0 0 1 2 0 2 1 0 0 0
0 0 0 0 2 0 0 2 0 0
0 0 0 0 1 0 0 1 0 0
0 0 0 0 0 2 1 0 1 2
0 0 0 0 0 0 0 1 0 1
0 0 0 0 0 0 0 2 1 0

This is a Semi-Eulerian Graph
First point = 1
Please start from an odd-degree vertex.
First point = 2

Euler: 2 1 4 2 3 4 5 6 8 9 10 8 7 5 3
*/

/*
Read adjacency matrix from a file:

0 1 0 0 0 1 0 0 0 0 0 0 1
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

The graph isn't an Eulerian / Semi-Eulerian Graph
*/