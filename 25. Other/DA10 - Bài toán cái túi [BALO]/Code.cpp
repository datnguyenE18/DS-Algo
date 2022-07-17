#include <bits/stdc++.h>
using namespace std;

struct packed
{
    int W, V;
};

void Optimize(int n, int M, packed A[], int **&F){
    F = new int *[n + 1];
    
    for (int i = 0; i <= n; i++)
        F[i] = new int[M + 1];
    
    memset(F[0], 0, M);
    
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= M; j++) {
            if (A[i].W <= j && A[i].V + F[i - 1][j - A[i].W] > F[i - 1][j])
                F[i][j] = F[i - 1][j - A[i].W] + A[i].V;
            else
                F[i][j] = F[i - 1][j];
        }
    
    cout << F[n][M] << endl;
}

int main(){
    int n, M, **F; cin >> n >> M;
    packed *A;
    A = new packed[n + 1];

    for (int i = 1; i <= n; i++)
        cin >> A[i].W >> A[i].V;

    Optimize(n, M, A, F);
    delete[] A;
    for (int i = 0; i <= n; i++)
        delete[] F[i];
    delete[] F;
}