public class Triangle {
    private float ab, bc, ca;

    public Triangle(Point a, Point b, Point c) {
        this.ab = a.distance(b);
        this.bc = b.distance(c);
        this.ca = c.distance(a);
    }

    public boolean valid() {
        if (ab + bc > ca && ab + ca > bc && bc + ca > ab)
            return true;
        return false;
    }

    public String getPerimeter() {
        return String.format("%.3f", ab + bc + ca);
    }
}