import java.util.Scanner;
import java.util.HashMap;

public class babelfish {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        HashMap<String, String> dict = new HashMap<String, String>();

        String[] ln = scn.nextLine().split(" ");
        do
        {
            dict.put(ln[1], ln[0]);
            ln = scn.nextLine().split(" ");
        }
        while (ln.length > 1);

        while (scn.hasNextLine())
        {
            String w = scn.nextLine();
            if (w.length() > 0)
                System.out.println(dict.getOrDefault(w, "eh"));
        }
    }
}