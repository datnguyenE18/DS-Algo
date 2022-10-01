import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class SinhVien {
    private String code = "B20DCCN001", name, clas;
    private Date birth;
    private float gpa;

    public SinhVien(String name, String clas, String birth, float gpa) throws ParseException {
        this.name = name;
        this.clas = clas;
        this.birth = new SimpleDateFormat("dd/MM/yyyy").parse(birth);
        this.gpa = gpa;
    }

    @Override
    public String toString() {

        return code + " " + name + " " + clas + " " + new SimpleDateFormat("dd/MM/yyyy").format(birth) + " "
                + String.format("%.2f", gpa);
    }

}