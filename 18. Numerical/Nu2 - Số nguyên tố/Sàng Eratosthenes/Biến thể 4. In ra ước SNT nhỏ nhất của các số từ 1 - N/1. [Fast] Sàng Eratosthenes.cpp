#include<bits/stdc++.h> 
using namespace std;

void Solution(int n) {
	vector <int> ans(n + 1, 0); // Tạo vector lưu các ước SNT nhỏ nhất của (n + 1) số từ 1 - N, mặc định ước SNT của tất cả các số ban đầu là 0 
	ans[1] = 1; //Ước SNT nhỏ nhất của 1 là chính nó

	for ( int i = 2; i <= n; i++ )  // Bắt đầu quét từ 2
		if ( ans[i] == 0 ) { //Nếu ước SNT nhỏ nhất là 0 thì bắt đầu thực hiện lệnh dưới. Thực ra sau lệnh dưới thì tất cả các bội của i =2,3,5,... sẽ khác 0 mà trở về đúng i
			ans[i] = i; // Gán ước SNT nhỏ nhất ban đầu cho i = 2,3,5,... là chính nó 
			for ( int j = i * i; j <= n; j += i ) //Bắt đầu quét các bội của i để thay đổi ước SNT nhỏ nhất của nó từ 0 về đúng i, lượt sau không cần quét vòng if trên nữa
				if ( ans[j] == 0 )
					ans[j] = i; //Thay đổi các ước SNT nhỏ nhất của bội của i về đúng i
		}

	for ( int i = 1; i <= n; i++ )
		cout << ans[i] << " "; //In ra ước SNT nhỏ nhất
	cout << endl;
}

int main() {
	int t, n; cin >> t;
	while ( t-- ) {
		cin >> n;
		Solution(n);
	}
}
