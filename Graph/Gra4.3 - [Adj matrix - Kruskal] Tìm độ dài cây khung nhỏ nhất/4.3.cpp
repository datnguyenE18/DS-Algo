#include<bits/stdc++.h>
using namespace std;
#define MAX 10005 // Số đỉnh tối đa trong đề bài

int ver, // Số đỉnh 
	edg, // Số cạnh
	par[MAX], D[MAX]; // 2 mảng sử dụng cho Disjoint Set

// Cấu trúc để lưu đồ thị:
struct edge {
	int u, v, // 2 đỉnh
		w; // Weight: trọng số cạnh
};

vector<edge> edges; // Danh sách các cạnh

void read_ed_lst() {
	ifstream FileIn;
	FileIn.open("graph.dat", ios_base::in);

	FileIn >> ver >> edg;
	edges.resize(edg);

	for ( edge &e : edges )
		FileIn >> e.u >> e.v >> e.w;

	FileIn.close();
	cout << "Read Edge List of Weighted Graph from a file: \n";
}

void dis_ed_lst() {
	cout << "Edge" << "		" << "Weight\n";
	for ( edge &e : edges )
		cout << e.u << "-" << e.v << "		  " << e.w << endl;
}

// Tìm xem u thuộc cây nào
int findParent(int u) {
	if ( par[u] != u ) par[u] = findParent(par[u]);
	return par[u];
}

// Hợp nhất 2 cây chứa u và v,
// Trả về false nếu không thể hợp nhất
bool join(int u, int v) {
	int U = findParent(u);
	int V = findParent(v);
	if ( U == V ) return false;
	if ( D[U] == D[V] ) D[U]++;
	if ( D[U] < D[V] ) par[U] = V;
	else par[V] = U;
	return true;
}

bool cmp(const edge &a, const edge &b) {
	return a.w < b.w;
}

void kruskal() {
	sort(edges.begin(), edges.end(), cmp); // Sắp xếp lại các cạnh theo trọng số tăng dần

	// Khởi tạo cấu trúc Disjoint Set
	for ( int i = 1; i <= ver; i++ ) {
		par[i] = i;
		D[i] = 0;
	}

	// Lưu tổng trọng số các cạnh trong cây khung nhỏ nhất
	int MSTweight = 0;

	// Duyệt qua các cạnh theo thứ tự đã sắp xếp
	for ( edge &e : edges ) {
		// Thử hợp nhất 2 cây chứa u và v
		if ( join(e.u, e.v) ) {
			// Hợp nhất thành công, ta thêm e và kết quả
			MSTweight += e.w;
		}
	}

	// Xuất kết quả
	cout << "\n=> MSTweight : " << MSTweight;
}

int main() {
	read_ed_lst();
	dis_ed_lst();
	kruskal();
}

/*
Read Edge List of Weighted Graph from a file:
Edge            Weight
1-2               2
1-3               1
1-4               3
2-3               2
2-6               5
2-7               5
3-4               4
3-6               5
4-5               5
4-6               5
5-6               6
5-10              6
6-7               6
6-8               6
6-9               6
6-10              6
7-8               6
8-9               7
8-12              7
8-13              7
9-10              7
9-11              7
10-11             7
10-12             7
11-12             8

=> MSTweight : 60
*/