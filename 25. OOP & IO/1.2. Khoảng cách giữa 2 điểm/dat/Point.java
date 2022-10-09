public class Point {
    private double x;
    private double y;

    public Point() {
    }

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public Point(Point p) {
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public double distance(Point secondPoint) {
        double subX = Math.pow(this.x - secondPoint.getX(), 2);
        double subY = Math.pow(this.y - secondPoint.getY(), 2);
        return Math.sqrt(subX + subY);
    }

    public static double distance(Point p1, Point p2) {
        double subX = Math.pow(p1.getX() - p2.getX(), 2);
        double subY = Math.pow(p1.getY() - p2.getY(), 2);
        return Math.sqrt(subX + subY);
    }

    @Override
    public String toString() {
        return String.format("%.4f", x);
    }
}