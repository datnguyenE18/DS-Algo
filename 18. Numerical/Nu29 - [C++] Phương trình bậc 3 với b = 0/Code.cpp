#include<bits/stdc++.h>
using namespace std;

void ptb3(int a, int b, int c)
{
    float dt, k, x;

    dt = -3 * a * b;
    k = (-27 * pow(a, 2) * c) / (2 * sqrt(pow(fabs(dt), 3)));
    x = (sqrt(fabs(dt)) / (3 * a)) * (pow((k + sqrt(k * k + 1)), 1.0 / 3) - pow(-(k - sqrt(k * k + 1)), 1.0 / 3));
    cout << setprecision(4) << fixed << -x << endl;
}

int main()
{
    int T = 0, A, B, C;
    cin >> T;
    while (T--)
    {
        cin >> A >> B >> C;
        ptb3(A, B, C);
    }
}