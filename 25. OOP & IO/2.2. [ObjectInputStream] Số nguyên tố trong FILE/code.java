import java.io.*;
import java.util.*;

public class Main {

    private static boolean isPrime(Integer n) {
        if (n < 2)
            return false;
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        ObjectInputStream sc = new ObjectInputStream(new FileInputStream("SONGUYEN.in"));
        ArrayList<Integer> ds = (ArrayList<Integer>) sc.readObject();
        int a[] = new int[100001];
        for (Integer i : ds) {
            if (isPrime(i)) {
                a[i]++;
            }
        }

        for (int i = 0; i < 10000; i++) {
            if (a[i] > 0) {
                System.out.println(i + " " + a[i]);
            }
        }
    }

}
