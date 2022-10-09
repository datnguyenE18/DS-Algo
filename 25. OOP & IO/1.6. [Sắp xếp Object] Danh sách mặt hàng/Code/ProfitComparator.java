import java.util.Comparator;

public class ProfitComparator implements Comparator<MatHang> {

    public int compare(MatHang o1, MatHang o2) {
        int profit1 = o1.getProfit();
        int profit2 = o2.getProfit();
        if (profit1 > profit2) {
            return -1;
        } else if (profit1 == profit2) {
            return 0;
        } else {
            return 1;
        }
    }
}