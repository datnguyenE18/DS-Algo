#include <iostream>
#define p 123456789
using namespace std;
long long n,k;


long long pow(long long x){
    if (x==0) return 1;
    if (x==1) return n;
    long long tg=pow(x/2);
    long long nhan=(tg*tg) % p;
    if (x % 2 == 1) nhan=(nhan*n) % p;
    return nhan;
}

int main(){
    int t;
    cin >> t;
    n=2;
    while (t--){
        cin >> k;
        cout << pow(k-1) << endl;
    }
}
