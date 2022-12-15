
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    static ArrayList<Integer> dske[] = new ArrayList[1001];
    static boolean chuaxet[] = new boolean[1001];
    static int truoc[] = new int[1001];

    public static void bfs(int u) {
        Queue<Integer> q = new LinkedList<>();
        q.add(u);
        chuaxet[u] = false;
        while (!q.isEmpty()) {
            int v = q.poll();
            for (Integer x : dske[v]) {
                if (chuaxet[x]) {
                    q.add(x);
                    chuaxet[x] = false;
                    truoc[x] = v;
                }
            }
        }
    }

    public static void duongdi(int s, int t) {
        bfs(s);
        if (chuaxet[t]) {
            System.out.println("No path");
        } else {
            ArrayList<Integer> kq = new ArrayList<>();
            int x = t;
            while (x != s) {
                kq.add(x);
                x = truoc[x];
            }
            kq.add(s);
            Collections.reverse(kq);
            for (Integer tmp : kq) {
                System.out.print(tmp + " ");
            }
        }
        System.out.println("");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int test = sc.nextInt();
        while (test-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int s = sc.nextInt();

            for (int i = 0; i <= n; i++) {
                dske[i] = new ArrayList<>();
                chuaxet[i] = true;
                truoc[i] = 0;
            }

            for (int i = 1; i <= m; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                dske[u].add(v);
                dske[v].add(u);
            }

            for (int i = 1; i <= n; i++) {
                if (s == i) {
                    continue;
                }
                duongdi(s, i);
            }
        }
    }
}
