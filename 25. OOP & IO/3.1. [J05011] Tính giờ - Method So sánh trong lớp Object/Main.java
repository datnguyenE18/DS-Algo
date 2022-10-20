import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        List<Gamer> ds = new ArrayList<>();
        while (t-- > 0) {
            ds.add(new Gamer(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        Collections.sort(ds);
        for (Gamer g : ds) {
            System.out.println(g);
        }
    }
}
