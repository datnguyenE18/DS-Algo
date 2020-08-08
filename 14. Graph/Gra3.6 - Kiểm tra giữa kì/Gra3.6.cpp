#include<bits/stdc++.h>
using namespace std;
#define MAX 1001

int ver,
	adj_mat[MAX][MAX],
	node,
	Pre[MAX],
	count0;
bool visited[MAX];
double density;

//Khởi tạo:
void init() {
	for ( int i = 1; i <= ver; i++ )
		visited[i] = false;
}

//Hàm sinh số ngẫu nhiên trong khoảng [0 , 1]:
double prob() {
	return (double) rand() / RAND_MAX;
}

//Hàm tạo ma trận kề ngẫu nhiên từ ver và density cho trước
void rand_graph() {
	int edge_count = 0;

	//Ban đầu tạo ma trận ver đỉnh chỉ chứa 0 (Tức các đỉnh rời rạc không nối với nhau):
	for ( int i = 0; i < ver; i++ ) {
		for ( int j = 0; j < ver; j++ )
			adj_mat[i][j] = 0;
	}

	//Tìm ngẫu nhiên vị trí trong ma trận (tìm các đỉnh để nối với nhau):
	for ( int i = 0; i < ver; i++ ) {
		for ( int j = i + 1; j < ver; j++ ) {
			if ( prob() < density ) { //density càng lớn thì càng nhiều đỉnh được nối
				adj_mat[i][j] = 1;
				adj_mat[j][i] = 1;
				edge_count++;
			}
		}
	}
	cout << "\n Created random graph with density " << density << " vs actual density is:  " << (double) 2 * edge_count / ( ver * ver ) << ":\n\n";
}

//Đọc ma trận kề từ file
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

//In ra ma trận kề vừa Đọc / Tạo
void dis_adj_mat() {
	for ( int i = 1; i <= ver; i++ ) {
		for ( int j = 1; j <= ver; j++ )
			cout << adj_mat[i][j] << " ";
		cout << endl;
	}
}

//Duyệt DFS:
void DFS(int node) {
	stack<int> stack0;
	stack0.push(node);
	visited[node] = true;
	cout << node << " ";

	while ( !stack0.empty() ) {
		node = stack0.top();
		stack0.pop();
		for ( int i = 1; i <= ver; i++ ) {
			if ( adj_mat[node][i] == 1 && visited[i] == false ) {
				cout << i << " ";
				stack0.push(node);
				stack0.push(i);
				visited[i] = true;
				break;
			}
		}
	}
}

//Duyệt BFS:
void BFS(int node) {
	queue<int> queue0;
	queue0.push(node);
	visited[node] = true;

	while ( !queue0.empty() ) {
		node = queue0.front();
		queue0.pop();
		cout << node << " ";
		for ( int i = 1; i <= ver; i++ ) {
			if ( adj_mat[node][i] = 1 && visited[i] == false ) {
				queue0.push(i);
				visited[i] = true;
			}
		}
	}
}

//Xác định thành phần liên thông:
void conComp() {
	int count0 = 0;
	for ( int i = 1; i <= ver; i++ ) {
		if ( visited[i] == false ) {
			count0++;
			cout << " * Connected component " << count0 << ": ";
			DFS(i);
		}
	}
	cout << "\n=> Number of connected components: " << count0 << "\n";
}

void DFS_path(int node) {
	stack<int> stack0;
	stack0.push(node);
	visited[node] = true;

	while ( !stack0.empty() ) {
		node = stack0.top();
		stack0.pop();

		for ( int i = 1; i <= ver; i++ ) {
			if ( adj_mat[node][i] == 1 && visited[i] == false ) {
				Pre[i] = node;
				visited[i] = true;
				stack0.push(node);
				stack0.push(i);
				break;
			}
		}
	}
}

void BFS_path(int node) {
	queue<int>queue0;
	queue0.push(node);
	visited[node] = true;

	while ( !queue0.empty() ) {
		node = queue0.front();
		queue0.pop();

		for ( int i = 1; i <= ver; i++ ) {
			if ( adj_mat[node][i] == 1 && visited[i] == false ) {
				Pre[i] = node;
				queue0.push(i);
				visited[i] = true;
			}
		}
	}
}

// Tìm đường đi giữa 2 đỉnh:
void findPath() {
	int start_ver, end_ver;
	cout << "\nStarting Vertex: "; cin >> start_ver;
	cout << "\nEnding Vertex: "; cin >> end_ver;
	DFS_path(start_ver); //BFS_path(start_ver);

	if ( Pre[end_ver] == 0 )
		cout << "\nThe path from " << start_ver << " to " << end_ver << " is not exist!\n";
	else {
		cout << "\n=> Path: ";
		cout << end_ver;
		int temp = Pre[end_ver];
		while ( temp != start_ver ) {
			cout << " <- " << temp;
			temp = Pre[temp];
		}
		cout << " <- " << start_ver << "\n";
	}
}

//Duyệt BFS & DFS và trả về một giá trị:
int BFS_count(int node) {
	count0 = 1;
	queue<int>queue0;
	queue0.push(node);
	visited[node] = true;

	while ( !queue0.empty() ) {
		node = queue0.front();
		queue0.pop();

		for ( int i = 1; i <= ver; i++ ) {
			if ( adj_mat[node][i] == 1 && visited[i] == false ) {
				count0++;
				queue0.push(i);
				visited[i] = true;
			}
		}
	}
	return count0;
}

int DFS_count(int node) {
	count0 = 1;
	stack<int>stack0;
	stack0.push(node);
	visited[node] = true;

	while ( !stack0.empty() ) {
		node = stack0.top();
		stack0.pop();

		for ( int i = 1; i <= ver; i++ ) {
			if ( adj_mat[node][i] == 1 && visited[i] == false ) {
				count0++;
				stack0.push(node);
				stack0.push(i);
				visited[i] = true;
				break;
			}
		}
	}
	return count0;
}

//Xác định tính liên thông mạnh / yếu:
bool is_Strong_Connected() {
	for ( int i = 1; i <= ver; i++ ) {
		if ( DFS_count(i) != ver ) return false; //BFS_count(i)
		init();
	} return true;
}

//Tìm đỉnh trụ:
void Finding_Cut_Vertices() {
	vector<int> res;

	for ( int i = 1; i <= ver; i++ ) {
		visited[i] = true;

		if ( i == 1 && DFS_count(2) != ver - 1 ) // BFS_count(2)
			res.push_back(i);
		else if ( i != 1 && DFS_count(1) != ver - 1 ) // BFS_count(2)
			res.push_back(i);
		init();
	}

	cout << "\nAll Cut Vertices: ";
	if ( !res.empty() ) {
		for ( int i = 0; i < res.size(); i++ )
			cout << res[i] << " ";
		cout << "\n";
	} else cout << "Empty!\n";
}

//Duyệt cạnh cầu:
void Finding_Bridges() {
	vector<vector<int>>res;

	for ( int i = 1; i <= ver; i++ ) {
		for ( int j = 1; j <= ver; j++ ) {
			if ( adj_mat[i][j] == 1 ) {
				adj_mat[i][j] = adj_mat[j][i] = 0;
				if ( DFS_count(1) != ver ) { // BFS_count(1)
					vector<int> temp;
					temp.push_back(i);
					temp.push_back(j);
					res.push_back(temp);
				}
				adj_mat[i][j] = 1;
				init();
			}
		}
	}

	if ( !res.empty() ) {
		for ( int i = 0; i < res.size(); i++ ) {
			cout << "( ";
			for ( int j = 0; j < res[i].size(); j++ )
				cout << res[i][j] << " ";
			cout << ") ";
		}
	} else cout << "Empty!\n";
}

void menu() {
	cout << "//-----------------------------------------------------------------//\n";
	cout << "//Project: Basic Graph                                             //\n";
	cout << "//Author: Nguyen Dat, Computer Science, CIE, PTIT                  //\n";
	cout << "//Date: May, 2020                                                  //\n";
	cout << "//-----------------------------------------------------------------//\n";

	//B1: Chọn ma trận (tạo ngẫu nhiên / đọc từ file):
	cout << "\n************************************************************************************\n";
	cout << "B1: CHON MA TRAN: \n";
	cout << "0 - Read From File \n\n1 - Random Graph\n\nYour option: ";
	int option; cin >> option;
	cout << "--------------------------------------------------------------------------------------\n";
	if ( option == 1 ) {
		cout << "Vertex = "; cin >> ver;
		cout << "Density = "; cin >> density;
		rand_graph();
	} else if ( option == 0 ) {
		read_adj_mat();
	} else {
		cout << "Invalid option\n";
		system("pause");
		return;
	}
	dis_adj_mat();

	//Chọn chức năng xử lý ma trận:
	cout << "\n************************************************************************************\n";
	cout << "B2: CHON CHUC NANG XU LY MA TRAN:";
	cout << "\n\n0 - Duyet do thi voi BFS & DFS \n\n1 - Xac dinh thanh phan lien thong\n\n2 - Tim duong di giua cac dinh\n\n3 - Kiem tra tinh lien thong\n\n4 - Tim dinh tru\n\n5 - Duyet canh cau\n\nYour option: ";
	cin >> option;
	cout << "---------------------------------------------------------------------------------------\n";
	switch ( option ) {
		case 0:
			{
				init();
				cout << "node ="; cin >> node;
				cout << "\nDFS(" << node << ") = "; DFS(node);
				init();
				cout << "\nBFS(" << node << ") = "; BFS(node);
				break;
			}

		case 1:
			{
				init();
				conComp();
				break;
			}

		case 2:
			{
				init();
				findPath();
				break;
			}

		case 3:
			{
				init();
				if ( is_Strong_Connected() ) cout << "\nSTRONG!\n";
				else cout << "\nWEAK!\n";
				break;
			}

		case 4:
			{
				init();
				Finding_Cut_Vertices();
				break;
			}

		case 5:
			{
				init();
				Finding_Bridges();
				break;
			}

		default:
			break;
	}
}

int main() {
	menu();
}