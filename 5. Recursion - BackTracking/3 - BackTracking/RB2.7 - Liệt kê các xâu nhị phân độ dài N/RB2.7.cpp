#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int n, //Độ dài xâu nhị phân 
	X[MAX]; //Xâu nhị phân X có độ dài tối đa là MAX = 100

void display () {
	for ( int i = 0; i < n; i++ )
		cout << X[i];
	cout << endl;
}

void qlNhiPhan ( int i ) { // Quay Lui Nhị Phân
	for ( int j = 0; j < 2; j++ ) { // giá trị X có thể nhận là 1 và 0 (nhị phân)
		X[i] = j; //thử giá trị X[i] có thể nhận
		if ( i == n - 1 ) display (); //Nếu là phần tử cuối cùng rồi thì in ra
		else qlNhiPhan ( i + 1 ); //Nếu chưa thì xét vị trí tiếp theo
	}
}

int main () {
	int t; cin >> t;
	while ( t-- ) {
		cin >> n;
		qlNhiPhan ( 0 );
	}
	system ( "pause" );
}