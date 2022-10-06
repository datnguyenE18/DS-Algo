#include<bits/stdc++.h>
using namespace std;

int m, //sinh xâu nhị phân có độ dài m = (1,2,3,...) 
n, // số nguyên N (1 ≤ N ≤ 500)
a[100]; //Lưu tạm kết quả nhị phân vào các ô để chuyển sang int

bool stop; //kiểm soát vòng lặp tăng m;
long long res = 1e18; //1e18 = 1000000000000000000LL

// Quay lui Sinh nhị phân:
void Try ( int i ) {
	for ( int val = 0; val <= 1; val++ ) { //val là các giá trị có thể gán cho các vị trí trong a
		a[i] = val;
		if ( i == m ) { //Nếu vị trí i là phần tử cuối của dãy, tức là đã sinh được 1 chuỗi nhị phân có độ dài m trong a rồi
			long long s = 0; //Lưu tạm kết quả dạng int

			//chuyển a[100] sang int rồi lưu vào s
			for ( int l = 1; l <= m; l++ )
				s = 10 * s + a[l]; //lúc này s chỉ chứa 0 và 1

			s *= 9; //nhân lên để s chứa 0 và 9 đúng với yêu cầu đề bài

			if ( s % n == 0 && s >= n ) { // s >= n để tránh kết quả là 0
				res = min ( s, res ); //vì bộ các xâu nhị phân được sinh ra , chuyển sang int * 9 thì có nhiều hơn 1 số chia hết cho n, nên ta chọn số nhỏ nhất gồm res được lưu trước đó và s mới
				stop = true;
			}
		} else Try ( i + 1 ); //Nếu vị trí i chưa phải là phần tử cuối của dãy thì ta gán giá trị cho phần tử sau i
	}
}

int main () {
	int t; cin >> t;
	while ( t-- ) {
		m = 1;
		stop = false;
		res = 1e18; //Kết quả
		cin >> n;
		while ( !stop ) {
			Try ( 1 ); // mỗi lượt Try là duyệt xong được 1 bộ xâu nhị phân có độ dài m 
			m++;
		} cout << res << "\n";
	} system ( "pause" );
}