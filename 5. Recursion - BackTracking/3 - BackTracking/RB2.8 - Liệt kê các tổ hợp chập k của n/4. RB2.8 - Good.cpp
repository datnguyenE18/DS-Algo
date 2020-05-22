#include<bits/stdc++.h>
using namespace std;
#define MAX 20

int n, k, num[MAX];

void display() {
	for ( int i = 1; i <= k; i++ ) {
		cout << num[i];
	} cout << " ";
}

void Try(int i) {
	for ( int j = num[i - 1] + 1; j <= n - k + i; j++ ) { //mọi giá trị V mà có thể gán cho phần tử x[i] đang xét
		num[i] = j; //Thử gán x[i] = V
		if ( i == k ) { //Nếu x[i] là phần tử kết thúc cấu hình
			display(); //In ra cấu hình
		} else Try(i + 1);
	}
}

int main() {
	int t; cin >> t;
	while ( t-- ) {
		num[0] = 0;
		cin >> n >> k;
		Try(1);
		cout << "\n";
	}
}