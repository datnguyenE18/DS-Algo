import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    private static void listNP(int n) {
        Queue<String> tmp = new LinkedList<>();
        tmp.add("0");
        tmp.add("1");

        int i = 0;
        while (!tmp.isEmpty()) {
            StringBuilder s = new StringBuilder();
            String temp = tmp.poll();
            String res = temp + s.append(temp).reverse().toString();

            if (res.length() > n) {
                break;
            }
            System.out.print(res + " ");
            tmp.offer(temp + "0");
            tmp.offer(temp + "1");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int N = sc.nextInt();
            listNP(N);
        }
    }

}