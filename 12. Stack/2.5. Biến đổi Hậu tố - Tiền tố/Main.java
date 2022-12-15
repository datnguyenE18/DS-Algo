
import java.util.*;
import java.text.*;

public class T215_BienDoiHauToTienTo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while(t-->0)
        {
            String s = sc.nextLine();
            Result(s);
        }
    }
    public static void Result(String s)
    {
        Stack<String> st = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i)=='+'
                    ||s.charAt(i)=='-'
                    ||s.charAt(i)=='*'
                    ||s.charAt(i)=='/')
            {
                String a = st.peek();st.pop();
                String b = st.peek();st.pop();
                String tmp = Character.toString(s.charAt(i))+b+a;
                st.push(tmp);
            }
            else st.push(Character.toString(s.charAt(i)));
        }
        System.out.println(st.peek());
    }
}
