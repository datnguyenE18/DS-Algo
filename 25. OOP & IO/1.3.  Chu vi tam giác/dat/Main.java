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
                    y2 = sc.nextDouble(),
                    x3 = sc.nextDouble(),
                    y3 = sc.nextDouble();

            Point p1 = new Point(x1, y1);
            Point p2 = new Point(x2, y2);
            Point p3 = new Point(x3, y3);

            double dis12 = Point.distance(p1, p2);
            double dis13 = Point.distance(p1, p3);
            double dis23 = Point.distance(p2, p3);

            if (dis12 + dis13 <= dis23 || dis12 + dis23 <= dis13 || dis13 + dis23 <= dis12) {
                System.out.println("INVALID");
            } else {
                System.out.println(String.format("%.3f", dis12 + dis23 + dis13));
            }

        }
    }
}