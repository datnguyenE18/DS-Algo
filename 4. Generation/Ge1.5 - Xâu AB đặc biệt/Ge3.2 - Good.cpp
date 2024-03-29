﻿#include<iostream>
using namespace std;

bool check = false;
int n, k, count0 = 0; //count0 là biến đếm kết quả.
char a[17];
string s[1000000]; //chứa các dãy thỏa mãn

//cấu hình ban đầu
void init() {
	for ( int i = 1; i <= n; i++ )
		a[i] = 'A';
}

//Kiểm tra tính hợp lệ của chuỗi
bool kt() {
	int d = 0, t = 1;
	for ( int i = 1; i < n; i++ ) {
		if ( a[i] == 'A' && a[i + 1] == 'A' ) {
			t++;
			if ( t >= k ) d++;
		} else t = 1;
	}

	if ( d == 1 ) return true;
	else return false;
}

//Lưu chuỗi hợp lệ
void dem() {
	if ( kt() ) {
		s[count0] = "";
		for ( int i = 1; i <= n; i++ )
			s[count0] += a[i];
		count0++;
	}
}

void sinh() {
	int i = n;
	while ( a[i] == 'B' ) {
		a[i] = 'A';
		i--;
	}
	if ( i == 0 ) check = true;
	else a[i] = 'B';
}

int main() {
	cin >> n >> k;
	init();
	while ( !check ) {
		sinh();
		dem();
	}
	cout << count0 << endl;
	for ( int i = 0; i < count0; i++ )
		cout << s[i] << endl;
}