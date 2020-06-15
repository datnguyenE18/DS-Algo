﻿#include<bits/stdc++.h>
using namespace std;
#define MAX 1001

int ver, adj_mat[MAX][MAX], count0;
bool visited[MAX];

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
			if ( visited[t] == false && adj_mat[node][t] == 1 ) {
				count0++;
				queue0.push(t);
				visited[t] = true;
			}
		}
	}
	return count0;
}

// Kiểm tra ma trận vô hướng có là Euler không:
bool check() {
	for ( int i = 1; i <= ver; i++ ) visited[i] = false;

	if ( /*BFS(1)*/ BFS(1) != ver ) return false;
	for ( int i = 1; i <= ver; i++ ) {
		int sum = 0;
		for ( int j = 1; j <= ver; j++ )
			sum += adj_mat[i][j];
		if ( sum % 2 != 0 ) return false;
	} return true;
}

void Euler_Cycle(int node) {
	stack<int> stack0, CE;
	stack0.push(node);
	while ( !stack0.empty() ) {
		int counter = 0;
		node = stack0.top();
		for ( int i = 1; i <= ver; i++ )
			if ( adj_mat[node][i] == 0 )
				counter++;
		if ( counter != ver ) {
			for ( int t = 1; t <= ver; t++ ) {
				if ( adj_mat[node][t] == 1 ) {
					stack0.push(t);
					adj_mat[node][t] = adj_mat[t][node] = 0;
					break;
				}
			}
		} else {
			CE.push(node);
			stack0.pop();
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
	if ( check() ) {
		cout << "First point = ";  cin >> node;
		Euler_Cycle(node);
	} else cout << "The graph isn't an Eulerian Graph";
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