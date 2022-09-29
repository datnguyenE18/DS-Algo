#include <bits\stdc++.h>
using namespace std;

int main () {
	int sec, h, p; cin >> sec;
	cout << sec / 120 << ":" << sec / 60 << ":" << sec - ( sec / 60 ) * 60 << endl;
	system ( "pause" );
}