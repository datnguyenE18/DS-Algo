#include<bits/stdc++.h>
using namespace std;
#define MAX 1001

int ver, adj_mat[MAX][MAX];
bool visited[MAX];

void read_adj_mat() {
	ifstream FileIn;
	FileIn.open("graph2.dat", ios_base::in);
	FileIn >> ver;
	for ( int i = 1; i <= ver; i++ ) {
		for ( int j = 1; j <= ver; j++ )
			FileIn >> adj_mat[i][j];
		visited[i] = false;
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

void tree_DFS(int node) {
	stack <int> stack0;
	vector<vector<int>> T;
	stack0.push(node);
	visited[node] = true;

	while ( !stack0.empty() ) {
		node = stack0.top();
		stack0.pop();

		for ( int i = 1; i <= ver; i++ ) {
			if ( adj_mat[node][i] == 1 && visited[i] == false ) {
				vector<int> temp;
				stack0.push(node);
				stack0.push(i);
				visited[i] = true;
				temp.push_back(node);
				temp.push_back(i);
				T.push_back(temp);
				break;
			}
		}
	}

	if ( T.size() < ver - 1 ) cout << "Graph is not connected!";
	else {
		cout << "We have the set of edges of spanning tree T:\n";
		for ( int i = 0; i < T.size(); i++ ) {
			cout << "( ";
			for ( int j = 0; j < T[i].size(); j++ )
				cout << T[i][j] << " ";
			cout << ") ";
		}
	}
}

int main() {
	read_adj_mat();
	dis_adj_mat();
	int node;
	cout << "First point = "; cin >> node;
	tree_DFS(node);
}

/*
graph1.dat:
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
First point = 1
We have the set of edges of spanning tree T:
( 1 2 ) ( 2 3 ) ( 3 4 ) ( 3 5 ) ( 5 6 ) ( 6 7 ) ( 7 8 ) ( 8 9 ) ( 9 10 ) ( 10 11 ) ( 11 12 ) ( 12 13 )
*/

/*
graph2.dat:
Read adjacency matrix from a file:

0 1 0 0 0 0 0 1 0
1 0 1 0 0 0 0 1 0
0 1 0 1 0 1 0 0 1
0 0 1 0 1 1 0 0 0
0 0 0 1 0 1 0 0 0
0 0 1 1 1 0 1 0 0
0 0 0 0 0 1 0 1 1
1 1 0 0 0 0 1 0 1
0 0 1 0 0 0 1 1 0
First point = 1
We have the set of edges of spanning tree T:
( 1 2 ) ( 2 3 ) ( 3 4 ) ( 4 5 ) ( 5 6 ) ( 6 7 ) ( 7 8 ) ( 8 9 )
*/