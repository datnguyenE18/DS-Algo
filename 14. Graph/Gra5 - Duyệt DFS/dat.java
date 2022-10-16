import java.util.*;

public class Main {
    static Boolean[] visited = new Boolean[1001];
    static ArrayList<Integer> ed_lst[] = new ArrayList[1001];

    private static void DFS(int u) {
        if (!visited[u]) {
            return;
        }

        visited[u] = false;
        System.out.print(u + " ");

        for (Integer i : ed_lst[u]) {
            if (visited[i]) {
                DFS(i);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int vr = sc.nextInt(),
                    ed = sc.nextInt(),
                    u = sc.nextInt();

            for (int i = 0; i <= vr; i++) {
                ed_lst[i] = new ArrayList<>();
                visited[i] = true;
            }

            for (int i = 0; i < ed; i++) {
                int d1 = sc.nextInt(),
                        d2 = sc.nextInt();
                ed_lst[d1].add(d2);
                ed_lst[d2].add(d1);
            }

            System.out.print("DFS(" + u + ") = ");
            DFS(u);
            System.out.println();
        }
    }

}