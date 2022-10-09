import java.text.ParseException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws ParseException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            double x1 = sc.nextDouble(),
                    y1 = sc.nextDouble(),
                    x2 = sc.nextDouble(),
                    y2 = sc.nextDouble();

            Point p1 = new Point(x1, y1),
                    p2 = new Point(x2, y2);

            double dis12 = p1.distance(p1, p2);
            System.out.println(String.format("%.4f", dis12));

        }
    }
}