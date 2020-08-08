#include<bits/stdc++.h>
using namespace std;

int ver, //Số đỉnh	
	edg, // Số cạnh
	i, j,
	start_ver, end_ver, //Đỉnh đầu và đỉnh cuối
	previous[1001]; //previous[i] ghi lại đỉnh ở trước đỉnh i (i ∈ tất cả các đỉnh khi duyệt DFS / BFS)
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

//Duyệt theo ngăn xếp:
void DFS_stack(int node) {
	int stack0[100];
	visited[node] = true;
	int index = 1, s;
	stack0[index] = node;
	while ( index > 0 ) {
		s = stack0[index];   //gan s = phan tu dau ngan xep
		index--;
		for ( int i = 0; i < adj_list[s].size(); i++ ) {
			if ( visited[adj_list[s][i]] == false ) {    // voi moi phan tu thuoc mang k[i] chua xet  
				previous[adj_list[s][i]] = s;
				visited[adj_list[s][i]] = true;
				index++;
				stack0[index] = s;            // gan lai s de sau do co the duyet lai
				index++;
				stack0[index] = adj_list[s][i];      //gan phan tu thoa man la phan tu dau ngan xep
				break;
			}
		}
	}
}

//Duyệt theo queue:
void BFS_queue(int node) {
	queue<int>queue0;
	queue0.push(node);
	visited[node] = true;

	while ( !queue0.empty() ) {
		int s = queue0.front();
		queue0.pop();
		for ( int i = 0; i < adj_list[s].size(); i++ ) {
			if ( visited[adj_list[s][i]] == false ) {
				previous[adj_list[s][i]] = s;
				queue0.push(adj_list[s][i]);
				visited[adj_list[s][i]] = true;
			}
		}
	}
}

//Truy vết:
void findPath() {
	cout << "\nStarting Vertex: "; cin >> start_ver;
	cout << "\nEnding Vertex: "; cin >> end_ver;
	DFS_stack(start_ver);
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
	cout << "Vertex: "; cin >> ver;
	cout << "Density: "; cin >> density;

	rand_adj_list();
	dis_adj_list();

	Reinit();
	findPath();
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


Starting Vertex: 1

Ending Vertex: 15

 => Path: 15 <- 12 <- 18 <- 16 <- 7 <- 11 <- 10 <- 4 <- 14 <- 20 <- 13 <- 19 <- 6 <- 2 <- 1
*/