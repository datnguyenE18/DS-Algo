#include<bits/stdc++.h>
using namespace std;

int componentSize(vector<vector<bool>> matrix, int vertex) {
	bool visited[11];
	int n = matrix.size(),
		cnt0 = 1;
	for ( int i = 0; i < n; i++ )
		visited[i] = false;

	stack<int> st;
	st.push(vertex);
	visited[vertex] = true;

	while ( !st.empty() ) {
		vertex = st.top();
		st.pop();
		for ( int i = 0; i < n; i++ ) {
			if ( matrix[vertex][i] && visited[i] == false ) {
				cnt0++;
				st.push(vertex);
				st.push(i);
				visited[i] = true;
				break;
			}
		}
	}
	return cnt0;
}

int main() {
	int starting_point; cin >> starting_point;
	vector < vector<bool>> matrix { {false, true, false}, {true, false, false}, {false, false, false} };
	cout << componentSize(matrix, starting_point);
}

/*
0
2
*/