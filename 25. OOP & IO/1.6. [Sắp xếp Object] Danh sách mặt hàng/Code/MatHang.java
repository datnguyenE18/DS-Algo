import java.util.Comparator;

public class MatHang implements Comparator<MatHang> {
    private String code = "MH0", name, dv;
    private int buy, sell, profit;

    public MatHang(String num, String name, String dv, int buy, int sell) {
        this.code += num;
        this.name = name;
        this.dv = dv;
        this.buy = buy;
        this.sell = sell;
        this.profit = sell - buy;
    }

    public void setProfit(int profit) {
        this.profit = profit;
    }

    public int getProfit() {
        return profit;
    }

    @Override
    public String toString() {
        return code + " " + name + " " + dv + " " + buy + " " + sell + " " + profit;
    }

    @Override
    public int compare(MatHang o1, MatHang o2) {
        int age1 = o1.getProfit();
        int age2 = o2.getProfit();
        if (age1 > age2) {
            return -1;
        } else if (age1 == age2) {
            return 0;
        } else {
            return 1;
        }
    }
}