import java.util.*;

public class Main {
    static int n, k, start;
    static long base = 100000l;
    static long d[] = new long[100005];
    static PriorityQueue<Long> q = new PriorityQueue<>();
    static boolean daxet[] = new boolean[100005];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            n = sc.nextInt();
            k = sc.nextInt();
            start = sc.nextInt();
            ArrayList<ArrayList<Long>> list = new ArrayList<>();
            for (int i = 0; i <= n; i++) {
                list.add(new ArrayList<>());
                daxet[i] = false;
                d[i] = (int) 1e9;
            }
            for (int i = 1; i <= k; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                int c = sc.nextInt();

                list.get(u).add(1L * (c * base + v));
                list.get(v).add(1L * (c * base + u));
            }
            d[start] = 0;
            daxet[start] = true;
            for (long x : list.get(start)) {
                q.add(x);
                d[(int) (x % base)] = x / base;

            }
            while (!q.isEmpty()) {
                long tmp = q.remove();
                int u = (int) (tmp % base);
                long value1 = tmp / base;
                if (daxet[u] && value1 != d[u])
                    continue;
                daxet[u] = true;
                for (long x : list.get(u)) {
                    int v = (int) (x % base);
                    if (daxet[v])
                        continue;
                    long value2 = x / base;
                    if (d[v] > value1 + value2) {
                        d[v] = value1 + value2;
                        q.add(1l * (base * d[v] + v));
                    }
                }
            }
            for (int i = 1; i <= n; i++) {
                if (i == start)
                    System.out.print(0 + " ");
                else
                    System.out.print(d[i] + " ");
            }
            System.out.println();
        }
    }
}