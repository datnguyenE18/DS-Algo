#include <bits/stdc++.h> 
#define MAX 500 // Số lớn nhất có thể tính giai thừa
using namespace std;

int multiply(int x, int res[], int size) { //nhan x voi cac so trong mang
    int carry = 0;  // thiet lap carry =0      
    for ( int i = 0; i < size; i++ ) { //nhan tung so trong res[]
        int t = res[i] * x + carry; //nhan voi so cong voi carry  
        res[i] = t % 10;//luu so cuoi cung cua t vao res[i]             
        carry = t / 10;//carry carryoc chia cho 10     
    }
    // Put carry in res and increase result size 
    while ( carry ) {
        res[size] = carry % 10;
        carry = carry / 10;
        size++;
    }
    return size;
}

void factorial(int n) { //tim n! cua so lon
    int res[MAX]; //tao mang luu cac chu so cua n!  
    // Initialize result 
    res[0] = 1; //kh
    int size = 1;
    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n 
    for ( int x = 2; x <= n; x++ )
        size = multiply(x, res, size);

    cout << "Factorial of given number is \n";
    for ( int i = size - 1; i >= 0; i-- )
        cout << res[i];
}

int main() {
    factorial(15);
    return 0;
}
