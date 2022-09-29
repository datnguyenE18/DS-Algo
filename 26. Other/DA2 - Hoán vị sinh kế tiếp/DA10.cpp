#include<iostream>
using namespace std;

void swap ( int &x, int &y ) {
	int temp = x;
	x = y;
	y = temp;
}

void contr_origin_config ( int *a, int n ) { // Construct Original Configuration
	for ( int i = 1; i <= n; i++ ) a[i] = i;
}

void print_config ( int *a, int n ) { //Print configuration
	for ( int i = 1; i <= n; i++ ) cout << a[i];
	cout << endl;
}

void sort_up ( int *a, int n, int posi ) { //Bubble Sort 
	for ( int i = posi; i < n; i++ ) {
		for ( int j = i + 1; j <= n; j++ ) {
			if ( a[i] > a[j] )
				swap ( a[i], a[j] );
		}
	}
}

int main () {
	int *a;
	int n;
	cout << "Nhap n: "; cin >> n;
	a = new int[n];
	contr_origin_config ( a, n );
	print_config ( a, n );

	while ( true ) {
		int i;
		for ( i = n; i > 0; i-- ) { //scan from last to head place
			if ( i == 1 ) {			// if it is arranged in descending,
				system ( "pause" );
				return 0;			// End!
			}
			if ( a[i - 1] < a[i] ) break;
		}

		for ( int j = n; j >= i; j-- ) {
			if ( a[j] > a[i - 1] ) {
				swap ( a[j], a[i - 1] );
				sort_up ( a, n, i );
				print_config ( a, n );
				break;
			}
		}
	} system ( "pause" );
}