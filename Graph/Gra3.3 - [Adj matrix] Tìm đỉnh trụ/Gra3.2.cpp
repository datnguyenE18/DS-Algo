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

void Finding_Cut_Vertices() {
	vector<int> res;

	for ( int i = 1; i <= ver; i++ ) {
		visited[i] = true;
		if ( i == 1 && DFS(2) != ver - 1 )
			res.push_back(i);
		else if ( i != 1 && DFS(1) != ver - 1 )
			res.push_back(i);
		Reinit();
	}

	cout << "\nAll cut vertices of Graph: ";
	if ( !res.empty() ) {
		for ( int i = 0; i < res.size(); i++ )
			cout << res[i] << " ";
		cout << endl;
	} else cout << "(empty)\n";
}

int main() {
	read_adj_mat();
	dis_adj_mat();
	Finding_Cut_Vertices();
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

All cut vertices of Graph: 3 5 9 10
*/
