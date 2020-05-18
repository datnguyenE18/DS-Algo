#include<bits/stdc++.h>
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

int DFS(int node) {
	cout << "	DFS(" << node << ") = ";
	stack<int> stack0;
	stack0.push(node);
	visited[node] = true;
	int count0 = 1;
	cout << node << " ";

	while ( !stack0.empty() ) {
		node = stack0.top();
		stack0.pop();

		for ( int i = 1; i <= ver; i++ ) {
			if ( adj_mat[node][i] == 1 && visited[i] == false ) {
				count0++;
				cout << i << " ";
				visited[i] = true;
				stack0.push(node);
				stack0.push(i);
				break;
			}
		}
	}
	cout << "\n";
	return count0;
}

void Finding_Bridges() {
	vector<vector<int>> res;
	for ( int i = 1; i <= ver; i++ ) {
		for ( int j = 1; j <= ver; j++ ) {
			if ( adj_mat[i][j] == 1 ) {
				cout << "Egde: (" << i << ", " << j << ") -- ";
				adj_mat[i][j] = adj_mat[j][i] = 0;
				if ( DFS(1) != ver ) {
					vector<int> temp;
					temp.push_back(i);
					temp.push_back(j);
					res.push_back(temp);
				}
				Reinit();
				adj_mat[i][j] = 1; 
			}
		}
	}
	cout << "\n => All bridges: ";
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
Egde: (1, 2) --         DFS(1) = 1 3 2 4 5 6 7 8 9 10 11 12 13
Egde: (1, 3) --         DFS(1) = 1 2 3 4 5 6 7 8 9 10 11 12 13
Egde: (1, 4) --         DFS(1) = 1 2 3 4 5 6 7 8 9 10 11 12 13
Egde: (2, 3) --         DFS(1) = 1 2 4 3 5 6 7 8 9 10 11 12 13
Egde: (2, 4) --         DFS(1) = 1 2 3 4 5 6 7 8 9 10 11 12 13
Egde: (3, 4) --         DFS(1) = 1 2 3 5 6 7 8 9 10 11 12 13 4
Egde: (3, 5) --         DFS(1) = 1 2 3 4
Egde: (5, 6) --         DFS(1) = 1 2 3 4 5 7 6 9 8 10 11 12 13
Egde: (5, 7) --         DFS(1) = 1 2 3 4 5 6 7 8 9 10 11 12 13
Egde: (5, 8) --         DFS(1) = 1 2 3 4 5 6 7 8 9 10 11 12 13
Egde: (5, 9) --         DFS(1) = 1 2 3 4 5 6 7 8 9 10 11 12 13
Egde: (6, 7) --         DFS(1) = 1 2 3 4 5 6 9 8 7 10 11 12 13
Egde: (6, 9) --         DFS(1) = 1 2 3 4 5 6 7 8 9 10 11 12 13
Egde: (7, 8) --         DFS(1) = 1 2 3 4 5 6 7 9 8 10 11 12 13
Egde: (8, 9) --         DFS(1) = 1 2 3 4 5 6 7 8 9 10 11 12 13
Egde: (9, 10) --        DFS(1) = 1 2 3 4 5 6 7 8 9
Egde: (10, 11) --       DFS(1) = 1 2 3 4 5 6 7 8 9 10 12 11 13
Egde: (10, 12) --       DFS(1) = 1 2 3 4 5 6 7 8 9 10 11 12 13
Egde: (10, 13) --       DFS(1) = 1 2 3 4 5 6 7 8 9 10 11 12 13
Egde: (11, 12) --       DFS(1) = 1 2 3 4 5 6 7 8 9 10 11 13 12
Egde: (11, 13) --       DFS(1) = 1 2 3 4 5 6 7 8 9 10 11 12 13
Egde: (12, 13) --       DFS(1) = 1 2 3 4 5 6 7 8 9 10 11 12 13

 => All bridges: ( 3 5 ) ( 9 10 )
*/