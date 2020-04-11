#include<iostream>
using namespace std;

//chuyen tu thap phan sang nhi phan.
long long bir ( long long n ) {
	if ( n == 1 )	return 1;
	else if ( n % 2 == 0 )	return 10 * bir ( n / 2 );
	else	return 10 * bir ( n / 2 ) + 1;
}

int main ( ) {
	long long t, n;
	cin >> t;
	while ( t-- ) {
		long long a = 1, d = 9;
		cin >> n;
		while ( d%n != 0 ) {
			a++;
			d = 9 * bir ( a );
		}
		cout << d << endl;
	} return 0;
}