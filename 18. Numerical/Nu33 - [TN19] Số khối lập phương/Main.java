import java.util.*;

public class Main {

    public static Vector<String> preProcess(long n) {
        Vector<String> preProcessedCubes = new Vector<>();
        for (long i = 1; i * i * i <= n; i++) {
            long iThCube = i * i * i;
            String cubeString = String.valueOf(iThCube);
            preProcessedCubes.add(cubeString);
        }
        return preProcessedCubes;
    }

    public static String findLargestCubeUtil(String num, Vector<String> preProcessedCubes) {
        Collections.reverse(preProcessedCubes);
        long totalCubes = preProcessedCubes.size();

        for (long i = 0; i < totalCubes; i++) {
            String currCube = preProcessedCubes.get((int) i);

            long digitsInCube = currCube.length();
            long index = 0;
            long digitsInNumber = num.length();
            for (long j = 0; j < digitsInNumber; j++) {

                if (num.charAt((int) j) == currCube.charAt((int) index)) {
                    index++;
                }

                if (digitsInCube == index) {
                    return currCube;
                }
            }
        }
        return "-1";
    }

    public static void findLargestCube(long n) {
        Vector<String> preProcessedCubes = preProcess(n);
        String num = String.valueOf(n);
        String ans = findLargestCubeUtil(num, preProcessedCubes);
        System.out.println(ans);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            long n = sc.nextLong();
            findLargestCube(n);
        }
    }
}
