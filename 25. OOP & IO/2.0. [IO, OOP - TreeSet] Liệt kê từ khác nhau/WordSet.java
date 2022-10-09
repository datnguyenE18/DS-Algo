import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.TreeSet;

public class WordSet {
    String file;

    public WordSet(String file) {
        this.file = file;
    }

    @Override
    public String toString() {
        TreeSet<String> tmp = new TreeSet<>();

        try (Scanner sc = new Scanner(new File(file))) {
            while (sc.hasNext()) {
                tmp.add(sc.next().toLowerCase());
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        for (String string : tmp) {
            System.out.println(string);
        }
        return "";
    }

}
