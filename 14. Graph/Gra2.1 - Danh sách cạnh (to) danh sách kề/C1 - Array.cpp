#include <bits/stdc++.h>
using namespace std;

struct AdjListNode {//định nghĩa danh sách kề của đỉnh
	int dest;//đỉnh kề của đỉnh
	struct AdjListNode* next; //con trỏ đến đỉnh kề tiếp theo
};

struct AdjList { //danh sách kề của đỉnh
	AdjListNode *head;//là một danh sách liên kết
};

class Graph {
	private:
	int V;//tập đỉnh của đồ thị
	AdjList* array;//mảng mỗi phần tử là một danh sách kề
	public:
	Graph ( int V ) {//constructor của lớp
		this->V = V; //thiết lập tập đỉnh V là V
		array = new AdjList[V];//cấp phát miền nhớ cho V danh sách liên kết
		for ( int i = 0; i < V; ++i ) //thiết lập tất cả các danh sách liên kết là NULL
			array[i].head = NULL;
	}

	AdjListNode* newAdjListNode ( int dest ) {//thêm một đỉnh mới vào danh sách kề
		AdjListNode* newNode = new AdjListNode; //cấp phát miền nhớ cho node
		newNode->dest = dest;//thiết lập node mới là một đỉnh kề dest
		newNode->next = NULL;//thiết lập liên kết cho đỉnh kề dest là NULL
		return newNode;//trả lại node kề mới
	}

	void addEdge ( int src, int dest ) {//src là đỉnh đầu, dest là đỉnh cuối của cạnh
		AdjListNode* newNode;
		newNode = newAdjListNode ( dest );//cấp phát miền nhớ cho đỉnh kề dest
		newNode->next = array[src].head;//danh sách kề của node src
		array[src].head = newNode;//liên kết dest với danh sách kề của src

		//đồ thị vô hướng ta thêm đoạn này. Đồ thị có hướng bỏ đoạn này
		newNode = newAdjListNode ( src );//thêm src vào danh sách kề của dest
		newNode->next = array[dest].head; //liên kết src với danh sách kề của dest
		array[dest].head = newNode;//node src được thêm vào dest
	}

	void printGraph () {//hien thi bieu dien
		int v;
		for ( v = 1; v < V; ++v ) {
			AdjListNode* pCrawl = array[v].head;
			cout << "\n Danh sach ke dinh " << v << "\n head "; //Danh sách kề đỉnh
			while ( pCrawl ) {
				cout << " -> " << pCrawl->dest;
				pCrawl = pCrawl->next;
			}
			cout << endl;
		}
	}
};//end class

int main () {
	ifstream fp ( "dothi.in" ); //mở file để đọc
	int n, m, dau, cuoi;
	fp >> n >> m;//đọc số đỉnh và số cạnh của đồ thị
	Graph gh ( n + 1 ); //gh là đồ thị n đỉnh tính từ 1, 2, .., n
	for ( int i = 1; i <= m; i++ ) { //duyệt m cạnh tiếp theo
		fp >> dau >> cuoi;//đọc một cạnh
		gh.addEdge ( dau, cuoi );//thêm cuoi vào list(dau) và thêm dau vào list(cuoi)
	}
	fp.close ();
	gh.printGraph ();
	system ( "pause" );
}