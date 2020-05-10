#include<bits/stdc++.h>
using namespace std;

int ver, //Số đỉnh
	edg, // Số cạnh
	node, i, j;
vector<int> adj_list[1001]; //vector lưu danh sách kề
double density; // Tỉ số
bool visited[1001]; // ma trận 2 chiều lưu tình trạng duyệt các đỉnh

// Khởi tạo visited (Tất cả đều chưa thăm)
void Reinit() {
	for ( i = 1; i < ver; i++ )
		visited[i] = false;
}

// Sinh số ngẫu nhiên trong khoảng [0, 1]
double prob() {
	return (double) rand() / RAND_MAX;
}

// Sinh ngẫu nhiên danh sách kề:
void rand_adj_list() {
	edg = 0;
	for ( i = 1; i <= ver; i++ ) {
		for ( j = i + 1; j <= ver; j++ ) {
			if ( prob() < density ) {
				adj_list[i].push_back(j);
				adj_list[j].push_back(i);
				edg++;
			}
		}
	}
	cout << "\n Created random list with density " << density << " vs actual density is " << (double) 2 * edg / ( ver * ver ) << ":\n\n";
}

//In danh sách kề vừa tạo
void dis_adj_list() {
	for ( i = 1; i <= ver; i++ ) {
		cout << "Adj{" << i << "}	={";
		for ( j = 0; j < adj_list[i].size(); j++ ) {
			cout << adj_list[i][j];
			if ( j == adj_list[i].size() - 1 ) break;
			cout << ", ";
		} cout << "}\n";
	} cout << "\n";
}

//Duyệt BFS theo queue:
void BFS_queue(int node) {
	queue<int>queue0;
	queue0.push(node);
	visited[node] = true;

	while ( !queue0.empty() ) {
		node = queue0.front();
		queue0.pop();
		cout << node << " ";
		for ( int i = 0; i < adj_list[node].size(); i++ ) {
			if ( visited[adj_list[node][i]] == 0 ) {
				queue0.push(adj_list[node][i]);
				visited[adj_list[node][i]] = true;
			}
		}
	}
}

//Duyệt DFS theo stack:
void DFS_stack(int node) {
	stack<int> stack0;
	cout << node << " ";
	visited[node] = true;
	stack0.push(node);

	while ( !stack0.empty() ) {
		node = stack0.top();
		stack0.pop();

		for ( int i = 0; i < adj_list[node].size(); i++ ) {
			if ( visited[adj_list[node][i]] == false ) {
				cout << adj_list[node][i] << " ";
				visited[adj_list[node][i]] = true;
				stack0.push(node);
				stack0.push(adj_list[node][i]);
				break;
			}
		}
	}
}


void conComp() {
	int count = 0;
	for ( i = 1; i <= ver; i++ ) {
		if ( visited[i] == false ) {
			count++;
			cout << " * Connected component " << count << ": ";
			BFS_queue(i);
			//DFS_stack(i);
		}
	}
	cout << "\n=> Number of connected components: " << count << "\n";
}

int main() {
	cout << "Vertex: "; cin >> ver;
	cout << "Density: "; cin >> density;

	rand_adj_list();
	dis_adj_list();

	Reinit();
	conComp();
}

/*
Vertex: 20
Density: 0.15

 Created random list with density 0.15 vs actual density is 0.155:

Adj{1}  ={2, 17, 18, 20}
Adj{2}  ={1, 6, 7, 8, 18}
Adj{3}  ={12}
Adj{4}  ={10, 12, 14, 15}
Adj{5}  ={15}
Adj{6}  ={2, 19}
Adj{7}  ={2, 9, 11, 16}
Adj{8}  ={2}
Adj{9}  ={7, 14, 17}
Adj{10} ={4, 11}
Adj{11} ={7, 10}
Adj{12} ={3, 4, 15, 18}
Adj{13} ={19, 20}
Adj{14} ={4, 9, 20}
Adj{15} ={4, 5, 12}
Adj{16} ={7, 18, 19, 20}
Adj{17} ={1, 9}
Adj{18} ={1, 2, 12, 16, 19}
Adj{19} ={6, 13, 16, 18, 20}
Adj{20} ={1, 13, 14, 16, 19}

 * Connected component 1: 1 2 17 18 20 6 7 8 9 12 16 19 13 14 11 3 4 15 10 5
=> Number of connected components: 1
*/