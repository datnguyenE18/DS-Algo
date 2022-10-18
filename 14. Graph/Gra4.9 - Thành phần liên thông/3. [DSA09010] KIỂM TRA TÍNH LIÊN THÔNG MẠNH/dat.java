import java.util.*;

public class Main {
    static int n, m;
    static ArrayList<Integer> dske[] = new ArrayList[1005];
    static boolean chuaxet[] = new boolean[1005];

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while (t-- > 0) {
            n = in.nextInt();
            m = in.nextInt();
            for (int i = 0; i <= 1000; i++) {
                dske[i] = new ArrayList<>();
                chuaxet[i] = true;
            }
            for (int i = 1; i <= m; i++) {
                int u = in.nextInt(), v = in.nextInt();
                dske[u].add(v); // dske[v].add(u);
            }
            boolean check = true;
            dfs(1);
            for (int i = 1; i <= n; i++) {
                if (chuaxet[i]) {
                    check = false;
                    break;
                }
            }
            if (check)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }

    public static void dfs(int u) {
        chuaxet[u] = false;
        for (Integer v : dske[u]) {
            if (chuaxet[v])
                dfs(v);
        }
    }
}
