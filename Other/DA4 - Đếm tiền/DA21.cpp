#include <bits/stdc++.h>
using namespace std;

int main () {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int f = 0;
	int g = 0;
	int h = 0;
	int i = 0;
	int k = 0;
	int tongSoToTien = 0;

	cin >> a;
	b = a / 500;
	a = a % 500;
	c = a / 200;
	a = a % 200;
	d = a / 100;
	a = a % 100;
	e = a / 50;
	a = a % 50;
	f = a / 20;
	a = a % 20;
	g = a / 10;
	a = a % 10;
	h = a / 5;
	a = a % 5;
	i = a / 2;
	a = a % 2;
	k = a / 1;

	tongSoToTien = b + c + d + e + f + g + h + i + k;
	cout << tongSoToTien;

	system ( "pause" );
	return 0;
}
