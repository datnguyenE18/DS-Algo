import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    static ArrayList<Integer> edge[] = new ArrayList[301];
    static boolean visited[] = new boolean[301];

    private static void checklienthong(int n, int m) {
        visited[1] = true;
        DFS(1);

        boolean flag = true;

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                System.out.println(i);
                flag = false;
            }
        }

        if (flag) {
            System.out.println("0");
        }
    }

    private static void DFS(int s) {
        for (int i : edge[s]) {
            if (!visited[i]) {
                visited[i] = true;
                DFS(i);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), // đỉnh
                m = sc.nextInt(); // cạnh

        // init:
        for (int i = 0; i <= n; i++) {
            edge[i] = new ArrayList<>();
            visited[i] = false;
        }

        for (int i = 0; i < m; i++) {
            int st = sc.nextInt(),
                    en = sc.nextInt();
            edge[st].add(en);
            edge[en].add(st);
        }

        checklienthong(n, m);
    }

}