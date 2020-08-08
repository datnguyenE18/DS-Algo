int countTriangles(int[] x, int[] y)
{
    int size = x.length;
    int ans = 0;
    for (int i=0; i<size; i++)
        for (int j=i+1; j<size; j++)
        for (int k=j+1; k<size; k++) {
        int x1 = x[i] - x[j], y1 = y[i] - y[j];
        int x2 = x[i] - x[k], y2 = y[i] - y[k];
        if (x1*y2 != x2*y1)
            ans++;
    }
    return ans;
}
