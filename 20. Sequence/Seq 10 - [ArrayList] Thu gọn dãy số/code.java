import java.util.ArrayList;
import java.util.Scanner;

public class App {

    public static void reduceA(ArrayList<Integer> A) {
        boolean isContinue = true;
        while (isContinue) {
            isContinue = false;
            for (int i = 0; i < A.size() - 1; i++) {
                if ((A.get(i) + A.get(i + 1)) % 2 == 0) {
                    A.remove(i);
                    A.remove(i);
                    isContinue = true;
                }
            }
        }
        System.out.print(A.size());
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        ArrayList<Integer> A = new ArrayList<Integer>();
        for (int i = 0; i < N; i++) {
            A.add(sc.nextInt());
        }

        reduceA(A);
    }
}