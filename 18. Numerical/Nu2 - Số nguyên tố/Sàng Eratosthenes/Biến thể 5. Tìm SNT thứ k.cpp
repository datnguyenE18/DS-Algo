#include<bits/stdc++.h>
using namespace std;

int main () {
	bool *a;//có n+1 phần tử
	int n = 10000, k;
	cin >> k;
	a = new bool[n + 1];
	memset ( a, true, ( n + 1 )*sizeof( bool ) );//a[0]->a[n]=true
	for ( int i = 2; i <= sqrt ( n ); i++ ) {
		if ( a[i] == true )//nếu như số i là số nguyên tố thì bội của nó không là số nguyên tố
		{
			for ( int j = i + i; j <= n; j += i )//xét các bội của i
			{
				a[j] = false;
			}
		}
	}
	int count = 0;//xét xem đã đến số nguyên tố thứ bào nhiêu
	for ( int i = 2; i <= n; i++ ) {
		if ( a[i] == true ) {
			//cout<<i<<" ";
			count++;
		}
		if ( count == k ) {
			cout << i;
			break;
		}
	}
	system ( "pause" );
	return 0;
}