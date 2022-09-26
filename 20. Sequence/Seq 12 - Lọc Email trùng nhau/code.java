import java.util.Scanner;
import java.util.TreeSet;

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        TreeSet<String> email = new TreeSet<>();
        while (sc.hasNextLine()) {
            email.add(sc.nextLine().toLowerCase().trim());
        }

        for (String string : email) {
            System.out.println(string);
        }
    }
}
