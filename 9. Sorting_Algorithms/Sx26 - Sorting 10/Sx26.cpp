#include<bits/stdc++.h>
#define IOS() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long int ll;

int n;
vector<ll> a;

void Input() {
    cin >> n;
    a.resize(n);
    for ( ll &i : a ) cin >> i;
}

void Solve() {
    int check[10];
    vector<int> b;
    memset(check, 0, sizeof(check));
    for ( int i = 0; i < n; i++ ) {
        while ( a[i] > 0 ) {
            int du = a[i] % 10;
            a[i] /= 10;
            if ( check[du] == 0 ) {
                b.push_back(du);
                check[du] = 1;
            }
        }
    }
    sort(all(b));
    for ( int i : b ) cout << i << " ";
    cout << endl;
}

int main() {
    IOS()
        int test; cin >> test;
    while ( test-- ) {
        Input();
        Solve();
    }
}