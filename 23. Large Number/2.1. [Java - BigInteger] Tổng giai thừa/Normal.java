import java.util.*;

public class App {

    public static long gt(int a) {
        long k = 1;
        for (int i = 1; i <= a; i++)
            k *= i;
        return k;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        long t = 0;
        for (int i = 1; i <= n; i++)
            t += gt(i);
        System.out.println(t);
    }

}