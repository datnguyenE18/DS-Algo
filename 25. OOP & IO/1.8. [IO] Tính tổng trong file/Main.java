import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("DATA.in"));
        long kq = 0;
        while (in.hasNext()) {
            String tmp = in.next();
            try {
                kq = kq + Integer.parseInt(tmp);
            } catch (NumberFormatException e) {
                continue;
            }
        }
        System.out.println(kq);
    }
}
