import java.util.Comparator;

public class TDComparator implements Comparator<ThiSinh> {

    public int compare(ThiSinh o1, ThiSinh o2) {
        if (o1.getTongdiem() > o2.getTongdiem())
            return -1;
        if (o1.getTongdiem() < o2.getTongdiem())
            return 1;
        else {
            String sub1 = o1.getMaTS().substring(3);
            String sub2 = o2.getMaTS().substring(3);
            return sub1.compareTo(sub2);
        }
    }
}