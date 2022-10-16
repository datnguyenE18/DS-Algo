import java.util.*;

public class Main {
    static ArrayList<Integer> near_lst[] = new ArrayList[1001];
    static boolean visited[] = new boolean[1001];
    static int bef[] = new int[1001];

    private static void track(int s, int i) {
        BFS(s);

        if (visited[i]) {
            System.out.println("No path");
        } else {
            ArrayList<Integer> res = new ArrayList<>();
            int u = i;
            while (u != s) {
                res.add(u);
                u = bef[u];
            }
            res.add(s);

            Collections.reverse(res);

            for (Integer integer : res) {
                System.out.print(integer + " ");
            }
            System.out.println();
        }
    }

    public static void BFS(int s) {
        Queue<Integer> que = new LinkedList<>();
        que.add(s);
        visited[s] = false;

        while (!que.isEmpty()) {
            int u = que.poll();
            for (Integer integer : near_lst[u]) {
                if (visited[integer]) {
                    que.add(integer);
                    visited[integer] = false;
                    bef[integer] = u;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt(),
                    m = sc.nextInt(),
                    s = sc.nextInt();

            // init:
            for (int i = 0; i <= n; i++) {
                near_lst[i] = new ArrayList<>();
                bef[i] = 0;
                visited[i] = true;
            }

            for (int i = 1; i <= m; i++) {
                int d1 = sc.nextInt(),
                        d2 = sc.nextInt();

                near_lst[d1].add(d2);
                near_lst[d2].add(d1);
            }

            for (int i = 1; i <= n; i++) {
                if (s == i) {
                    continue;
                }
                track(s, i);
            }
        }
    }

}