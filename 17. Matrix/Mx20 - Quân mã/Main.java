
import java.util.Scanner;

public class Main {

    static Scanner sc = new Scanner(System.in);

    static int map[][] = new int[2100][2100];
    static int vs[][] = new int[2100][2100];
    static int xF, yF;
    static int dirX[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    static int dirY[] = {-2, -1, 1, 2, 2, 1, -1, -2};

    public static void main(String[] args) {
        int t;
        t = sc.nextInt();
        for (int tc = 0; tc < t; tc++) {
            xF = sc.nextInt();
            yF = sc.nextInt();
            xF += 1000;
            yF += 1000;
            int k = sc.nextInt();
            reset();
            for (int l = 0; l < k; l++) {
                int a, b;
                a = sc.nextInt();
                b = sc.nextInt();
                map[a + 1000][b + 1000] = 1;
            }
            BFS();
            System.out.println(vs[xF][yF]);
        }
    }

    public static void BFS() {
        int front = 0;
        int rear = 0;
        int q[] = new int[10000005];
        int HS = 10000;
        q[rear] = 1000 * HS + 1000;
        vs[1000][1000] = 0;
        rear++;
        while (front < rear) {
            int curr = q[front];
            front++;
            int currX = curr / HS;
            int currY = curr % HS;
            if (currX == xF && currY == yF) {
                break;
            }
            for (int i = 0; i < 8; i++) {
                int nX = currX + dirX[i];
                int nY = currY + dirY[i];
                if (notOut(nX, nY) && map[nX][nY] == 0 && vs[nX][nY] == -1) {
                    vs[nX][nY] = vs[currX][currY] + 1;
                    q[rear] = nX * HS + nY;
                    rear++;
                }
            }
        }
    }

    public static boolean notOut(int row, int col) {
        if (row >= 0 && row <= 2000 && col >= 0 && col <= 2000) {
            return true;
        }
        return false;
    }

    public static void reset() {
        for (int i = 0; i <= 2005; i++) {
            for (int j = 0; j <= 2005; j++) {
                map[i][j] = 0;
                vs[i][j] = -1;
            }
        }
    }
}
