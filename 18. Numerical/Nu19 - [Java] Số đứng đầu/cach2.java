import java.util.*;

public class cach2 {
    private static void firstNum(int a[], int n){
        Stack<Integer> st = new Stack<>();
        int max = -1;
        for(int i = n - 1; i >= 0; i--){
            if(a[i] > max){
                max = a[i];
                st.push(a[i]);
            }
        }
        while(!st.empty()){
            System.out.print(st.lastElement() + " ");
            st.pop();
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int  t = scanner.nextInt();
        while(t-- > 0){
            int n = scanner.nextInt();
            int a[] = new int[n + 2];
            for(int i = 0; i < n; i++)
                a[i] = scanner.nextInt();
            firstNum(a, n);
        }
    }
}