import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static int N, M;
    static int map[][] = new int[1005][1005];
    static int vs[][] = new int[1005][1005];

    public static void main(String[] args) {
        int t;
        t = sc.nextInt();
        for (int tc = 0; tc < t; tc++) {
            M = sc.nextInt();
            N = sc.nextInt();
            for (int i = 1; i <= M; i++) {
                for (int j = 1; j <= N; j++) {
                    map[i][j] = sc.nextInt();
                    vs[i][j] = -1;
                }
            }
            vs[1][1] = 0;
            BFS();
            System.out.println(vs[M][N]);
        }
    }

    public static void BFS() {
        int front = 0;
        int rear = 0;
        int HS = 10000;
        int q[] = new int[100005];
        q[rear] = 1 * HS + 1;
        rear++;
        while (front < rear) {
            int curr = q[front];
            front++;
            int currX = curr / HS;
            int currY = curr % HS;
            int nX = currX + map[currX][currY];
            int nY = currY + map[currX][currY];
            if (nY <= N && nY >= 1 && vs[currX][nY] == -1) {
                vs[currX][nY] = vs[currX][currY] + 1;
                q[rear] = currX * HS + nY;
                rear++;
            }
            if (nX <= M && nX >= 1 && vs[nX][currY] == -1) {
                vs[nX][currY] = vs[currX][currY] + 1;
                q[rear] = nX * HS + currY;
                rear++;
            }
        }
    }

}
