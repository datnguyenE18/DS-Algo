import java.io.*;
import java.util.*;

public class Main {
    // Tiền xử lý
    private static String preProcess(String name) {
        name = name.replaceAll("\\s+", " ").trim().toLowerCase();
        String[] tmp = name.split(" ");
        name = tmp[tmp.length - 1];
        for (int i = 0; i < tmp.length - 1; i++)
            name += tmp[i].charAt(0);
        return name;
    }

    // Đọc file:
    private static List<String> read() throws FileNotFoundException {
        List<String> lst = new ArrayList<>();
        Scanner sc = new Scanner(new File("DANHSACH.in"));
        while (sc.hasNext())
            lst.add(sc.nextLine());
        return lst;
    }

    public static void main(String[] args) throws FileNotFoundException {
        HashMap<String, Integer> list = new HashMap<>();
        List<String> lst = read();

        for (String t : lst) {
            String name = preProcess(t);
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
