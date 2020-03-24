//Tim so lon nhat nho hon N bang mot phep bien doi
#include <bits/stdc++.h> 
using namespace std;

string Rearrang_Num ( string str ) {
	int len = str.length (); //lay do dai so
	int index = -1; //ghi nhan index ban dau
	//B1: tim tu ben phai chu so lon hon so tipe theo
	// 34125: ta tim duoc so 4
	for ( int i = len - 2; i >= 0; i-- ) {
		if ( str[i] > str[i + 1] ) {
			index = i; //ghi nhan index
			break;
		}
	}

	//B2: tim chu so lon nhat tu ben phai index nho hon A[index]  
	int smallGreatDgt = -1;
	for ( int i = len - 1; i > index; i-- ) {
		if ( str[i] < str[index] ) {
			if ( smallGreatDgt == -1 ) smallGreatDgt = i;
			else if ( str[i] >= str[smallGreatDgt] ) smallGreatDgt = i;
		}
	}
	if ( index == -1 ) //khong co cach trao doi
		return "-1";
	if ( index == 0 && str[smallGreatDgt] == '0' ) { //chu y test nay
		return "-1";
	}
	if ( smallGreatDgt != -1 ) { //test nay OK
		swap ( str[index], str[smallGreatDgt] );
		return str;
	} return "-1";
}

int main () {
	int T; cin >> T;
	string str;
	while ( T-- ) {
		cin >> str;
		cout << Rearrang_Num ( str ) << endl;
	} system ( "pause" );
}
