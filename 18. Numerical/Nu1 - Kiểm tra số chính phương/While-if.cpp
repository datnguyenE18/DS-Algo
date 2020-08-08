#include<iostream>
using namespace std;

int main () {
	int n, i = 0;
	cout << "===CHUONG TRINH XAC DINH SO CHINH PHUONG===" << endl;
	cin >> n;
	while ( i*i <= n ) {
		if ( i*i == n ) {
			cout << "La so chinh phuong" << endl;
			system ( "pause" );
			return 0;
		} ++i;
	}
	cout << "Khong phai so chinh phuong" << endl;
	system ( "pause" );
}
