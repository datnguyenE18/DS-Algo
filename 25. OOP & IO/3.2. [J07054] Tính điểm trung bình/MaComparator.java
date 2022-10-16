import java.util.Comparator;

public class MaComparator implements Comparator<SinhVien> {

    public int compare(SinhVien o1, SinhVien o2) {
        if (Float.parseFloat(o1.getTb()) < Float.parseFloat(o2.getTb()))
            return 1;
        if (Float.parseFloat(o1.getTb()) > Float.parseFloat(o2.getTb()))
            return -1;
        return o1.getMa().compareTo(o2.getMa());
    }
}
