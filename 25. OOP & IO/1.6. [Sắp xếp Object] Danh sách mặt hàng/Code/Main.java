import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<MatHang> list = new ArrayList<MatHang>();
        int M = sc.nextInt();
        sc.nextLine();

        for (int i = 1; i <= M; i++) {
            String name = sc.nextLine();
            String dv = sc.nextLine();
            int buy = sc.nextInt();
            int sell = sc.nextInt();
            if (i < 10) {
                list.add(new MatHang("0" + Integer.toString(i), name, dv, buy, sell));
            } else {
                list.add(new MatHang(Integer.toString(i), name, dv, buy, sell));
            }
            sc.nextLine();
        }

        Collections.sort(list, new ProfitComparator());

        for (MatHang matHang : list) {
            System.out.println(matHang);
        }
    }
}
