import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int map[][] = new int[1005][1005];
        int t = sc.nextInt();
        while (t-- > 0) {
            int dinh = sc.nextInt();
            int canh = sc.nextInt();

            for (int i = 0; i <= dinh; i++) {
                for (int j = 0; j <= dinh; j++) {
                    map[i][j] = 0;
                }
            }

            for (int i = 1; i <= canh; i++) {
                int a = sc.nextInt(),
                        b = sc.nextInt();
                map[a][b] = 1;
            }

            for (int i = 1; i <= dinh; i++) {
                System.out.print(i + ": ");
                for (int j = 1; j <= dinh; j++) {
                    if (map[i][j] == 1) {
                        System.out.print(j + " ");
                    }
                }
                System.out.println();
            }
        }
    }
}