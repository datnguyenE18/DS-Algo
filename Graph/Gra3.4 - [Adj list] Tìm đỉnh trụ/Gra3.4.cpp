#include<bits/stdc++.h>
using namespace std;
#define MAX 1001

int ver, edg, count0;
double dens;
vector<int>adj_list[MAX];
bool visited[MAX];

double prob() {
	return (double) rand() / RAND_MAX;
}

void rand_graph() {
	edg = 0;

	for ( int i = 1; i <= ver; i++ ) {
		for ( int j = i + 1; j <= ver; j++ ) {
			if ( prob() < dens ) {
				adj_list[i].push_back(j);
				adj_list[j].push_back(i);
				edg++;
			}
		}
	}
}

void dis_adj_list() {
	cout << "\n Created random list with density " << dens << " vs actual density is:  " << (double) 2 * edg / ( ver * ver ) << ":\n\n";
	for ( int i = 1; i <= ver; i++ ) {
		cout << "Adj(" << i << ")	={";
		for ( int j = 0; j < adj_list[i].size(); j++ ) {
			cout << adj_list[i][j];
			if ( j == adj_list[i].size() - 1 ) break;
			cout << ", ";
		}
		cout << "}\n";
	}
	cout << endl;
}

void init() {
	for ( int i = 1; i <= ver; i++ )
		visited[i] = false;
}

int DFS(int node) {
	count0 = 1;
	stack<int> stack0;
	stack0.push(node);
	visited[node] = true;

	while ( !stack0.empty() ) {
		node = stack0.top();
		stack0.pop();
		for ( int i = 0; i < adj_list[node].size(); i++ ) {
			if ( visited[adj_list[node][i]] == false ) {
				count0++;
				stack0.push(node);
				stack0.push(adj_list[node][i]);
				visited[adj_list[node][i]] = true;
				break;
			}
		}
	}
	return count0;
}

int BFS(int node) {
	count0 = 1;
	queue<int>queue0;
	queue0.push(node);
	visited[node] = true;

	while ( !queue0.empty() ) {
		node = queue0.front();
		queue0.pop();
		for ( int i = 0; i < adj_list[node].size(); i++ ) {
			if ( visited[adj_list[node][i]] == false ) {
				count0++;
				queue0.push(adj_list[node][i]);
				visited[adj_list[node][i]] = true;
			}
		}
	}
	return count0;
}

void find_Cut_Ver() {
	vector<int> res;

	for ( int i = 1; i <= ver; i++ ) {
		visited[i] = true;
		if ( i == 1 && DFS(2) != ver - 1 ) //BFS(2)
			res.push_back(i);
		else if ( i != 1 && DFS(1) != ver - 1 ) //BFS(1)
			res.push_back(i);
		init();
	}

	cout << "\nAll cut vertices of Graph: ";
	if ( !res.empty() ) {
		for ( int i = 0; i < res.size(); i++ )
			cout << res[i] << " ";
		cout << endl;
	} else cout << "Empty!\n";
}

int main() {
	cout << "Vertex = "; cin >> ver;
	cout << "Density = "; cin >> dens;
	rand_graph();
	dis_adj_list();
	init();
	find_Cut_Ver();
}

/*
Vertex = 20
Density = 0.15

 Created random list with density 0.15 vs actual density is:  0.155:

Adj(1)  ={2, 17, 18, 20}
Adj(2)  ={1, 6, 7, 8, 18}
Adj(3)  ={12}
Adj(4)  ={10, 12, 14, 15}
Adj(5)  ={15}
Adj(6)  ={2, 19}
Adj(7)  ={2, 9, 11, 16}
Adj(8)  ={2}
Adj(9)  ={7, 14, 17}
Adj(10) ={4, 11}
Adj(11) ={7, 10}
Adj(12) ={3, 4, 15, 18}
Adj(13) ={19, 20}
Adj(14) ={4, 9, 20}
Adj(15) ={4, 5, 12}
Adj(16) ={7, 18, 19, 20}
Adj(17) ={1, 9}
Adj(18) ={1, 2, 12, 16, 19}
Adj(19) ={6, 13, 16, 18, 20}
Adj(20) ={1, 13, 14, 16, 19}


All cut vertices of Graph: 2 12 15
*/