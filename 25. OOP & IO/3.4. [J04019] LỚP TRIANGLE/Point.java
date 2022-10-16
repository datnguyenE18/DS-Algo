import java.util.*;

public class Point {
    private float x, y;

    public Point(float x, float y) {
        this.x = x;
        this.y = y;
    }

    public static Point nextPoint(Scanner sc) {
        return new Point(Float.parseFloat(sc.next()), Float.parseFloat(sc.next()));
    }

    public float distance(Point o) {
        return (float) Math.sqrt((x - o.x) * (x - o.x) + (y - o.y) * (y - o.y));
    }
}