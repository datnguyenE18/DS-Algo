import java.util.Scanner;

public class Main {
    static int N;
    static int map[][] = new int[150][150];
    static int vs[][] = new int[150][150];
    static int[] dirX = { 1, -1, 0, 0 };
    static int[] dirY = { 0, 0, 1, -1 };
    static int xS, yS, xF, yF;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 0; tc < t; tc++) {
            N = sc.nextInt();
            for (int i = 0; i < N; i++) {
                String s = new String();
                s = sc.next();
                for (int j = 0; j < N; j++) {
                    vs[i][j] = -1;
                    if (s.charAt(j) == '.') {
                        map[i][j] = 0;
                    } else {
                        map[i][j] = 1;
                    }
                }
            }
            xS = sc.nextInt();
            yS = sc.nextInt();
            xF = sc.nextInt();
            yF = sc.nextInt();
            BFS();
            System.out.println(vs[xF][yF]);
        }
    }

    public static boolean notOut(int row, int col) {
        if (row >= 0 && row < N && col >= 0 && col < N) {
            return true;
        }
        return false;
    }

    public static void BFS() {
        int front = 0;
        int rear = 0;
        int q[] = new int[100005];
        int HS = 10000;
        q[rear] = xS * HS + yS;
        vs[xS][yS] = 0;
        rear++;
        while (front < rear) {
            int curr = q[front];
            front++;
            int currX = curr / HS;
            int currY = curr % HS;
            for (int i = 0; i < 4; i++) {
                int nX = currX + dirX[i];
                int nY = currY + dirY[i];
                if (notOut(nX, nY) && vs[nX][nY] == -1 && map[nX][nY] == 0) {
                    while (notOut(nX, nY) && map[nX][nY] == 0) {
                        vs[nX][nY] = vs[currX][currY] + 1;
                        q[rear] = nX * HS + nY;
                        rear++;
                        nX += dirX[i];
                        nY += dirY[i];
                    }
                }
            }
        }
    }
}
