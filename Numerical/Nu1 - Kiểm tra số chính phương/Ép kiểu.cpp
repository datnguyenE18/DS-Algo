#include<bits\stdc++.h>
using namespace std;

int main () {
	int n;
	cout << "===CHUONG TRINH XAC DINH SO CHINH PHUONG===" << endl;
	cin >> n;
	int i = sqrt ( n );
	if ( i*i == n ) cout << "So chinh phuong" << endl;
	else cout << "Khong phai so chinh phuong" << endl;
	system ( "pause" );
}