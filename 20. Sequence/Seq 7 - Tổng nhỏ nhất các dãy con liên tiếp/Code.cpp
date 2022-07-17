#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void process()
{
    ll n; cin >> n;
    ll sumz = 0;
    vector<ll> a;
    vector<int> uoc;
    
    a.resize(n + 1);
    vector<ll> dp;
    dp.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
        cin >> a[i], sumz += a[i];
    dp[1] = a[1];
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + a[i];

    int k = sqrt(sumz);
    if (k * k == sumz)
        uoc.push_back(k);
    
    for (int i = 1; i <= k; i++) {
        if (sumz % i == 0) {
            uoc.push_back(i);
            uoc.push_back(sumz / i);
        }
    }
    
    sort(uoc.begin(), uoc.end());
    for (int i = 0; i < uoc.size(); i++){
        int indez = 0;
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (dp[j] - dp[indez] > uoc[i])
                break;
            if (dp[j] - dp[indez] == uoc[i]) {
                cnt += (j - indez);
                indez = j;
            }
        }
        if (cnt == n) {
            cout << uoc[i] << endl;
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 0; cin >> T;
    while (T--) {
        process();
    }
}