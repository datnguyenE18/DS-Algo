
import java.util.Scanner;

public class Main {

    static Scanner sc = new Scanner(System.in);
    static int map[][] = new int[1005][1005];
    static int vs[] = new int[1005];
    static int N, M, H;
    static int max;

    public static void main(String[] args) {
        N = sc.nextInt();
        M = sc.nextInt();
        H = sc.nextInt();
        for (int i = 0; i < N; i++) {
            vs[i] = 1005;
            for (int j = 0; j < N; j++) {
                map[i][j] = 0;
            }
        }
        for (int i = 0; i < M; i++) {
            int a;
            a = sc.nextInt();
            vs[a] = 0;
        }
        for (int i = 0; i < H; i++) {
            int a, b;
            a = sc.nextInt();
            b = sc.nextInt();
            map[a][b] = 1;
            map[b][a] = 1;
        }
        max = 0;
        for (int i = 0; i < N; i++) {
            if (vs[i] == 0) {
                BFS(i);
            }
        }

        for (int i = 0; i < N; i++) {
            if (vs[i] > max) {
                max = vs[i];
            }

        }

        for (int i = 0; i < N; i++) {
            if (vs[i] == max) {
                System.out.println(i);
                break;
            }
        }

    }

    public static void BFS(int n) {
        int front = 0;
        int rear = 0;
        int q[] = new int[1000100];
        q[rear] = n;
        rear++;
        while (front < rear) {
            int curr = q[front];
            front++;
            for (int i = 0; i < N; i++) {
                if (map[curr][i] == 1 && vs[i] > vs[curr] + 1) {

                    vs[i] = vs[curr] + 1;

                    q[rear] = i;
                    rear++;
                }
            }
        }
    }
}
