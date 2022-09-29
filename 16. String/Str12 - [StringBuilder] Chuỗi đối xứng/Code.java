import java.util.Scanner;

public class test {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            String begin = "";

            // Nhập chuỗi:
            for (int i = 0; i < n; i++) {
                begin += sc.nextInt();
            }

            // Tạo đối tượng StringBuilder để quản lý chuỗi trên:
            StringBuilder sb = new StringBuilder(begin);

            // Đảo ngược đối tượng StringBuilder rồi chuyển lại sang String:
            String rever = sb.reverse().toString();

            // So sánh chuỗi ban đầu với chuỗi sau khi bị đảo:
            if (begin.compareTo(rever) == 0) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}