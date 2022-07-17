#include <iostream>
#include <fstream>
using namespace std;

struct packed
{
    int W, V;
};
void GetInput(int &n, int &M, packed *&A)
{
    ifstream fi("BAG.INP");
    fi >> n >> M;
    A = new packed[n + 1];
    for (int i = 1; i <= n; i++)
    {
        fi >> A[i].W >> A[i].V;
        fi.get();
    }
    fi.close();
}
void Optimize(int n, int M, packed A[], int **&F)
{
    F = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        F[i] = new int[M + 1];
        memset(F[0], 0, M);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= M; j++)
        {
            if (A[i].W <= j && A[i].V + F[i - 1][j - A[i].W] > F[i - 1][j])
                F[i][j] = F[i - 1][j - A[i].W] + A[i].V;
            else
                F[i][j] = F[i - 1][j];
        }
}
void PutOutput(int **F, packed A[], int n, int M)
{
    ofstream fo("BAG.OUT");
    fo << F[n][M] << endl;
    for (; n > 0; n--)
        if (F[n][M] != F[n - 1][M])
        {
            fo << n << endl;
            M -= A[n].W;
        }
    fo.close();
}
int main()
{
    int n, M;
    packed *A;
    int **F;
    GetInput(n, M, A);
    Optimize(n, M, A, F);
    PutOutput(F, A, n, M);
    delete[] A;
    for (int i = 0; i <= n; i++)
        delete[] F[i];
    delete[] F;
}