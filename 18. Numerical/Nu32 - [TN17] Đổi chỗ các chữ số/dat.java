import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        int t;
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();
        for (int tc = 0; tc < t; tc++) {
            int n;
            n = sc.nextInt();
            int a[] = new int[15];
            String s = new String();
            s = sc.next();
            for (int i = 0; i < s.length(); i++) {
                a[i] = s.charAt(i) - '0';
            }
            for (int i = 0; i < s.length() - 1; i++) {
                int max = a[i];
                int index = 0;
                int flag = 0;
                for (int j = s.length(); j > i; j--) {
                    if (a[j] > max) {
                        flag = 1;
                        max = a[j];
                        index = j;
                    }
                }
                if (flag == 1 && n > 0) {
                    a[index] = a[i];
                    a[i] = max;
                    n--;
                }
            }
            for (int i = 0; i < s.length(); i++) {
                System.out.print(a[i]);
            }
            System.out.print("\n");
        }
    }

}
