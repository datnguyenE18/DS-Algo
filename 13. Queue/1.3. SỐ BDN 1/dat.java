import java.util.*;

public class Main {
    public static void Result(String s) {
        Queue<String> q = new LinkedList<>();
        q.add("1");
        int dem = 0;
        while (!q.isEmpty()) {
            String c = q.poll();
            if (c.length() < s.length()) {
                dem++;
                q.add(c + "0");
                q.add(c + "1");
            }
            if (c.length() == s.length() && c.compareTo(s) <= 0)
                dem++;
        }
        System.out.println(dem);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0) {
            String s = sc.nextLine();
            Result(s);
        }
    }

}
