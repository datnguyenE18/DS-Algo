﻿#include<bits/stdc++.h>
using namespace std;
#define MAX 1001

int ver,
adj_mat[MAX][MAX];
bool visited[MAX];

void Reinit() {
	for ( int i = 1; i <= ver; i++ )
		visited[i] = false;
}

void read_adj_mat() {
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
	}
}

int BFS(int node) {
	queue<int> queue0;
	int count0 = 1;
	queue0.push(node);
	visited[node] = true;

	while ( !queue0.empty() ) {
		node = queue0.front();
		queue0.pop();
		for ( int t = 1; t <= ver; t++ ) {
			if ( visited[t] == false && adj_mat[node][t] == 1 ) {
				count0++;
				queue0.push(t);
				visited[t] = true;
			}
		}
	}
	return count0;
}

int DFS(int node) {
	stack<int> stack0;
	stack0.push(node);
	visited[node] = true;
	int count0 = 1;

	while ( !stack0.empty() ) {
		node = stack0.top();
		stack0.pop();

		for ( int i = 1; i <= ver; i++ ) {
			if ( adj_mat[node][i] == 1 && visited[i] == false ) {
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

void Finding_Bridges() {
	vector<vector<int>> res;
	for ( int i = 1; i <= ver; i++ ) {
		for ( int j = 1; j <= ver; j++ ) {
			if ( adj_mat[i][j] == 1 ) {
				adj_mat[i][j] = adj_mat[j][i] = 0; //loại cạnh nối i với j ra khỏi tập cạnh để thực hiện DFS/BFS các cạnh còn lại
				if ( DFS(1) != ver ) {
					vector<int> temp;
					temp.push_back(i);
					temp.push_back(j);
					res.push_back(temp); //lưu 2 đỉnh của cạnh vào hàng của res
				}
				Reinit();
				adj_mat[i][j] = 1; //Khôi phục lại cạnh đã bỏ ở trên, nhưng chỉ khôi phục một vế để tránh kết quả lưu lại hai lần cạnh (a b) và (b a) 
			}
		}
	}
	cout << "\nAll bridges: ";
	if ( !res.empty() ) {
		for ( int i = 0; i < res.size(); i++ ) {
			cout << "( ";
			for ( int j = 0; j < res[i].size(); j++ )
				cout << res[i][j] << " ";
			cout << ") ";
		}
	} else cout << "(empty)\n";
}

int main() {
	read_adj_mat();
	dis_adj_mat();
	Finding_Bridges();
}

/*
Read adjacency matrix from a file:

0 1 1 1 0 0 0 0 0 0 0 0 0
1 0 1 1 0 0 0 0 0 0 0 0 0
1 1 0 1 1 0 0 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 1 1 1 1 0 0 0 0
0 0 0 0 1 0 1 0 1 0 0 0 0
0 0 0 0 1 1 0 1 0 0 0 0 0
0 0 0 0 1 0 1 0 1 0 0 0 0
0 0 0 0 1 1 0 1 0 1 0 0 0
0 0 0 0 0 0 0 0 1 0 1 1 1
0 0 0 0 0 0 0 0 0 1 0 1 1
0 0 0 0 0 0 0 0 0 1 1 0 1
0 0 0 0 0 0 0 0 0 1 1 1 0

All bridges: ( 3 5 ) ( 9 10 )
*/