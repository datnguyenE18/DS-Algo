#include<bits/stdc++.h>
using namespace std;
#define MAX 1001

int ver, i, j,
	start_ver, end_ver, //Đỉnh đầu và đỉnh cuối
	adj_mat[MAX][MAX],
	previous[MAX]; //previous[i] ghi lại đỉnh ở trước đỉnh i (i ∈ tất cả các đỉnh khi duyệt DFS / BFS)
bool visited[MAX];

void init() {
	for ( int i = 1; i <= ver; i++ ) {
		visited[i] = false;
		previous[i] = 0; //Ban đầu chưa ghi nhận được đỉnh nào trước đỉnh nào
	}
}

void reader() {
	ifstream FileIn;
	FileIn.open("graph.dat", ios_base::in);
	FileIn >> ver;

	for ( i = 1; i <= ver; i++ ) {
		for ( j = 1; j <= ver; j++ )
			FileIn >> adj_mat[i][j];
	}
	FileIn.close();
}

void dis_adj_mat() {
	cout << "Read adjacency matrix from a file: \n\n";
	for ( i = 1; i <= ver; i++ ) {
		for ( j = 1; j <= ver; j++ )
			cout << adj_mat[i][j] << " ";
		cout << endl;
	}
}

// Ghi nhận các đỉnh nằm trước những đỉnh khi duyệt DFS: 
void DFS_stack(int node) {
	stack<int>stack0;
	stack0.push(node);
	visited[node] = true;

	while ( !stack0.empty() ) {
		node = stack0.top();
		stack0.pop();
		for ( int i = 0; i <= ver; i++ ) {
			if ( visited[i] == false && adj_mat[node][i] == 1 ) {
				previous[i] = node; //Ghi nhận đỉnh 'node' nằm trước đỉnh 'i' ('node' gần đỉnh đầu 'Start_ver' hơn). Lưu ý: có thể có nhiều đỉnh cùng có 1 đỉnh trước
				visited[i] = true;
				stack0.push(node);
				stack0.push(i);
				break;
			}
		}
	}
}

void DFS_dequi(int node) {
	visited[node] = true;
	for ( int i = 1; i <= ver; i++ ) {
		if ( adj_mat[node][i] == 1 && visited[i] == false ) {
			previous[i] = node;
			DFS_dequi(i);
		}
	}
}

void BFS_queue(int node) {
	queue<int>queue0;
	queue0.push(node);
	visited[node] = true;

	while ( !queue0.empty() ) {
		node = queue0.front();
		queue0.pop();
		for ( int i = 1; i <= ver; i++ ) {
			if ( adj_mat[node][i] && visited[i] == false ) {
				queue0.push(i);
				previous[i] = node; //Lớp trên 'node' là lớp của 'i'
				visited[i] = true;
			}
		}
	}
}

//Truy vết:
void findPath() {
	cout << "\nStarting Vertex: "; cin >> start_ver;
	cout << "\nEnding Vertex: "; cin >> end_ver;
	DFS_stack(start_ver);
	//DFS_dequi(start_ver);
	//BFS_queue(start_ver);
	if ( previous[end_ver] == 0 ) //Nếu trước đỉnh end_ver không có đỉnh nào khi duyệt DFS/BFS thì tức là không có đường đi từ start_ver tới nó 
		cout << "\nThe path from " << start_ver << " to " << end_ver << " is not exist!\n";
	else {
		cout << "\n => Path: ";
		cout << end_ver;
		int temp = previous[end_ver]; //Truy vết từ end_ver lên đầu 
		while ( temp != start_ver ) {
			cout << " <- " << temp;
			temp = previous[temp]; //truy ngược lên trên
		}
		cout << " <- " << start_ver << "\n";
	}

}

int main() {
	reader();
	dis_adj_mat();
	init();
	findPath();
}

/*
Read adjacency matrix from a file:

0 1 1 0 0 0 0 0 0 0 1 0 0
1 0 0 1 0 1 0 0 0 0 0 0 0
1 0 0 1 0 0 0 0 0 0 0 0 0
0 1 1 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 1 0 0 0
0 1 0 1 0 0 1 1 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 1 0 0 0
0 0 0 0 1 0 0 0 0 0 0 0 1
0 0 0 0 1 0 0 1 0 0 0 0 0
1 0 0 0 0 0 0 0 0 0 0 1 1
0 0 0 0 0 0 0 0 0 0 1 0 1
0 0 0 0 0 0 0 0 1 0 1 1 0

Starting Vertex: 1

Ending Vertex: 9

 => Path: 9 <- 5 <- 10 <- 8 <- 6 <- 4 <- 2 <- 1
*/