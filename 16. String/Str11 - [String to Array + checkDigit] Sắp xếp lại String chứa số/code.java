import java.util.*;

public class test {

    private static void solve(String a) {
        char[] arr = a.toCharArray();
        Arrays.sort(arr);

        int res1 = 0;
        String res2 = "";

        for (int i = 0; i < arr.length; i++) {
            if (Character.isDigit(arr[i])) {
                res1 += Character.getNumericValue(arr[i]);
            } else {
                res2 += arr[i];
            }
        }

        System.out.println(res2 + res1);
    }

    public static void main(String[] agrs) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while (t-- > 0) {
            String a = sc.nextLine();
            solve(a);
        }

    }
}