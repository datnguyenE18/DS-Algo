#include<bits/stdc++.h>
using namespace std;

int n, //Số nguyên N
	res[505]; //res[i] chứa số nhỏ nhất chỉ chứa 0 và 9 chia hết cho i
bool visited[505]; 

void Init () {
	int dem = 0;
	queue<int> q;
	q.push ( 9 );
	while ( dem < 500 ) { //Mỗi lần xét là một bộ các số gồm 0 và 9 có độ dài tăng dần
		int t = q.front (); q.pop ();
		for ( int i = 1; i <= 500 && i <= t; i++ ) {
			if ( t % i == 0 && !visited[i] ) { //nếu t chia hết cho i thì visited[i] kiểm tra xem trước đó đã có số nào nhỏ hơn chia hết cho i chưa
				visited[i] = true; //Nếu chưa thì đánh dấy là có rồi
				res[i] = t; // Và thêm t vào res[i] xác nhận t lúc này là giá trị nhỏ nhất chia hết cho i
				dem++;
			}
		}
		q.push ( t * 10 ); //Lần lượt thêm 0
		q.push ( t * 10 + 9 ); // và 9 vào đằng sau cấu hình trước để xác định cấu hình tiếp theo
	}
}

int main () {
	int t; cin >> t;
	Init (); //Liệt kê tất cả các số nhỏ nhất res[i] chia hết cho i từ 1 đến 500
	while ( t-- ) {
		cin >> n;
		cout << res[n] << endl; //gọi ra res[i] là số nhỏ nhât chia hết cho i
	} system ( "pause" );
}
