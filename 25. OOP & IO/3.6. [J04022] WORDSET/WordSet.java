import java.util.Comparator;
import java.util.TreeSet;

public class WordSet {
    private String work;

    public WordSet(String work) {
        work = work.trim();
        work = work.replace("\\s+", " ").toLowerCase();
        this.work = work;
    }

    public String union(WordSet work2) {
        TreeSet<String> lst = new TreeSet<>(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return o1.compareTo(o2);
            }
        });

        String[] work2_array = work2.work.split(" ");
        for (int i = 0; i < work2_array.length; i++) {
            lst.add(work2_array[i]);
        }

        String[] work1_array = work.split(" ");
        for (int i = 0; i < work1_array.length; i++) {
            lst.add(work1_array[i]);
        }

        String res = "";

        for (String i : lst) {
            res += i + " ";
        }

        return res;

    }

    public String getWork() {
        return work;
    }

    public String intersection(WordSet work1) {
        TreeSet<String> lst = new TreeSet<>();
        TreeSet<String> res = new TreeSet<>(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return o1.compareTo(o2);
            }
        });
        String[] work2_array = this.work.split(" ");
        for (int i = 0; i < work2_array.length; i++) {
            lst.add(work2_array[i]);
        }

        String[] work1_array = work1.work.split(" ");
        for (int i = 0; i < work1_array.length; i++) {
            if (lst.contains(work1_array[i])) {
                res.add(work1_array[i]);
            }
        }

        String result = "";
        for (String i : res) {
            result += i + " ";
        }

        return result;
    }
}