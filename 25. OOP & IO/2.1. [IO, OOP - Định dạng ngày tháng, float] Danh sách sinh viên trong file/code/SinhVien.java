import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class SinhVien {
    private String name;
    private String lop;
    private Date birth;
    private float gpa;
    private String maSv = "B20DCCN";

    public SinhVien(String name, String lop, String birth, float gpa, int num) throws ParseException {
        this.name = name;
        this.lop = lop;
        this.birth = new SimpleDateFormat("dd/MM/yyyy").parse(birth);
        this.gpa = gpa;
        this.maSv += String.format("%03d", num);
    }

    @Override
    public String toString() {
        return maSv + " " + name + " " + lop + " " + new SimpleDateFormat("dd/MM/yyyy").format(birth) + " "
                + String.format(("%.2f"), gpa);
    }
}