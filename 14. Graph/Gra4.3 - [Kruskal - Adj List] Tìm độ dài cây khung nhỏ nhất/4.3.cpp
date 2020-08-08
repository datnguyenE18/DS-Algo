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

// Tìm xem u thuộc cây có gốc nào
int findParent(int u) {
	if ( par[u] != u ) par[u] = findParent(par[u]); // Những đỉnh chỉ có mình nó hoặc nó là gốc của một cây nào đó thì gốc của đỉnh đó là chính nó
	return par[u]; // Khi tìm thấy một đỉnh trong một cây mà gốc của đỉnh đó là chính nó thì tức nó là gốc của cây đó
}

// Hợp nhất 2 cây chứa u và v,
// Trả về false nếu không thể hợp nhất
bool join(int u, int v) {
	int U = findParent(u); // Gốc của đỉnh u
	int V = findParent(v); // Gốc của đỉnh v
	if ( U == V ) return false; // Nếu u và v có chung gốc thì không thể hợp nhất (nối chúng) với nhau vì như vậy sẽ tạo ra chu trình
	if ( D[U] == D[V] ) D[U]++; // Nếu độ dài 2 cây bằng nhau thì tăng độ dài 1 trong 2 cây lên, ở đây ta tăng độ dài của cây chứa u
	if ( D[U] < D[V] ) par[U] = V; // Còn nếu từ đầu 1 trong 2 cây, cây nào nhỏ hơn thì đưa về cùng gốc với cây lớn hơn 
	else par[V] = U; // Nếu không, sau bước tăng độ dài cây chứa u lên thì có D[U] > D[V] => đưa cây chứa v về cùng gốc với cây chứa u
	return true; // Trả về true
}

bool cmp(const edge &a, const edge &b) {
	return a.w < b.w;
}

void kruskal() {
	sort(edges.begin(), edges.end(), cmp); // Sắp xếp lại các cạnh theo trọng số tăng dần

	// Khởi tạo cấu trúc Disjoint Set
	for ( int i = 1; i <= ver; i++ ) {
		par[i] = i; // đầu tiên gốc của mỗi cây là chính nó (vì chỉ có một đỉnh)
		D[i] = 0; // đầu tiên độ dài các cây = 0 (vì chỉ có 1 đỉnh)
	}

	// Lưu tổng trọng số các cạnh trong cây khung nhỏ nhất
	cout << "\nMinimum spanning tree of the graph: \n";
	int MSTweight = 0;
	// Duyệt qua các cạnh theo thứ tự đã sắp xếp
	for ( edge &e : edges ) {
		// Thử hợp nhất 2 cây chứa u và v
		if ( join(e.u, e.v) ) {
			// Hợp nhất thành công, ta thêm e và kết quả
			cout << e.u << " - " << e.v << "	: " << e.w << endl;
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

Minimum spanning tree of the graph:
1 - 3   : 1
1 - 2   : 2
1 - 4   : 3
2 - 6   : 5
2 - 7   : 5
4 - 5   : 5
5 - 10  : 6
6 - 8   : 6
6 - 9   : 6
8 - 12  : 7
8 - 13  : 7
9 - 11  : 7

=> MSTweight : 60
*/