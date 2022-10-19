import java.util.Scanner;

public class Main {
    static int N;
    static int flag;
    static Scanner sc = new Scanner(System.in);
    static int map[][] = new int[20][20];
    static char res[] = new char[200];
    static int dirX[] = { 1, 0 };
    static int dirY[] = { 0, 1 };

    public static void main(String[] args) {
        int t;
        t = sc.nextInt();
        for (int tc = 0; tc < t; tc++) {
            N = sc.nextInt();
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    map[i][j] = sc.nextInt();
                }
            }
            flag = 0;
            if (map[0][0] == 1) {
                BT(0, 0, 0);
                if (flag == 0) {
                    System.out.print(-1);
                }
                System.out.print("\n");
            } else {
                System.out.println(-1);
            }
        }
    }

    public static void BT(int row, int col, int step) {
        if (row == N - 1 && col == N - 1) {
            flag = 1;
            for (int i = 0; i < step; i++) {
                System.out.print(res[i]);
            }
            System.out.print(" ");
            return;
        }
        for (int i = 0; i < 2; i++) {
            int nRow = row + dirX[i];
            int nCol = col + dirY[i];
            if (notOut(nRow, nCol) && map[nRow][nCol] == 1) {
                if (i == 0) {
                    res[step] = 'D';

                    BT(nRow, nCol, step + 1);

                }
                if (i == 1) {
                    res[step] = 'R';

                    BT(nRow, nCol, step + 1);

                }
            }
        }
    }

    public static boolean notOut(int row, int col) {
        if (row >= 0 && row < N && col >= 0 && col < N) {
            return true;
        }
        return false;
    }
}
