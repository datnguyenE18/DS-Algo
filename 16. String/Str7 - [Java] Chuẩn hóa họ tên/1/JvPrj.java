import java.util.*;

public class test {

    private static void format(String src) {
        // Xử lý cơ bản ban đầu: bỏ hết khoảng cách thừa + đưa hết về viết thường:
        src = src.replaceAll("\\s+", " ").trim().toLowerCase();

        // Lưu từng từ trong tên vào mảng tmp để xử lý
        String[] tmp = src.split(" ");

        // Xử lý viết hoa chữ cái đầu và đưa vào kết quả:
        String res = "";
        for (int i = 0; i < tmp.length; i++) {
            // Chuyển char sang String thì mới có toUpperCase()
            res += Character.toString(tmp[i].charAt(0)).toUpperCase();

            // substring(1) sẽ lấy từ phần tử thứ 1 của String đó đến hết String
            res += tmp[i].substring(1);

            if (i < tmp.length)
                res += " ";
        }

        System.out.println(res);
    }

    public static void main(String[] agrs) {
        // Khai báo
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while (t-- > 0) {
            String src = sc.nextLine();
            format(src);
        }

    }
}