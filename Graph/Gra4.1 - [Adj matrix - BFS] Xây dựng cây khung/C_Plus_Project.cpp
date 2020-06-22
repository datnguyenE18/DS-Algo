#include<bits/stdc++.h>
using namespace std;
#define MAX 1001

int ver, adj_mat[MAX][MAX];
bool visited[MAX];

void read_adj_mat() {
	ifstream FileIn;
	FileIn.open("graph.dat", ios_base::in);
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

void tree_BFS(int node) {
	queue<int> queue0;
	vector<vector<int>> T;
	queue0.push(node);
	visited[node] = true;

	while ( !queue0.empty() ) {
		node = queue0.front();
		queue0.pop();

		for ( int i = 1; i <= ver; i++ ) {
			if ( adj_mat[node][i] != 0 && visited[i] == false ) {
				vector<int> temp;
				queue0.push(i);
				visited[i] = true;
				temp.push_back(node);
				temp.push_back(i);
				T.push_back(temp);
			}
		}
	}

	if ( T.size() < ver - 1 ) cout << "Graph is not connected!";
	else {
		cout << "We have the set of edges of spanning tree T:\n";
		for ( int i = 0; i < T.size(); i++ ) {
			for ( int j = 0; j < T[i].size(); j++ )
				cout << T[i][j] << " ";
			cout << endl;
		}
	}

}
int main() {
	read_adj_mat();
	dis_adj_mat();
	int node;
	cout << "First point = "; cin >> node;
	tree_BFS(node);
}