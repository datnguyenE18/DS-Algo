import java.util.HashMap;
import java.util.Scanner;

public class Main {
    private static String preProcess(String name) {
        name = name.replaceAll("\\s+", " ").trim().toLowerCase();
        String[] tmp = name.split(" ");
        name = tmp[tmp.length - 1];
        for (int i = 0; i < tmp.length - 1; i++)
            name += tmp[i].charAt(0);
        return name;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        HashMap<String, Integer> list = new HashMap<>();
        int t = sc.nextInt();
        sc.nextLine();

        while (t-- > 0) {
            String name = preProcess(sc.nextLine());
            if (!list.containsKey(name)) {
                list.put(name, 1);
                System.out.println(name + "@ptit.edu.vn");
            } else {
                list.put(name, list.get(name) + 1);
                System.out.println(name + list.get(name) + "@ptit.edu.vn");
            }

        }
    }
}