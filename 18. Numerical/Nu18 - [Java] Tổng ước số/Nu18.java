import java.util.*;

public class Nu18 {

    static final int MAXN = 2000005;

    static int spf[] = new int[2000005];

    static void sieve() {
        spf[1] = 1;
        for (int i = 2; i < MAXN; i++) {
            spf[i] = i;
        }
        for (int i = 4; i < MAXN; i += 2) {
            spf[i] = 2;
        }
        for (int i = 3; i < Math.sqrt(MAXN); i++) {
            if (spf[i] == i) {
                for (int j = i * i; j < MAXN; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }

    static Vector<Integer> getFactorization(int x) {
        Vector<Integer> ret = new Vector<>();
        while (x != 1) {
            ret.add(spf[x]);
            x = x / spf[x];
        }
        return ret;
    }

    public static void main(String[] args) {
        sieve();
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        long ans = 0;
        while (n-- > 0) {
            int num = in.nextInt();
            Vector<Integer> p = getFactorization(num);
            for (int i = 0; i < p.size(); i++) {
                ans += (long)p.get(i);
            }
            
        }
        System.out.println(ans);
    }
}
