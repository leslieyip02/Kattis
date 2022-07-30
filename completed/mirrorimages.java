import java.util.Scanner;
import java.util.Arrays;
import java.io.PrintStream;

public class mirrorimages {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = Integer.parseInt(s.nextLine());
        for (int i = 1; i <= t; i++) {
            System.out.printf("Test %d\n", i);

            String[] params = s.nextLine().split(" ", 2);
            int r = Integer.parseInt(params[0]);
            int c = Integer.parseInt(params[1]);

            String[] img = new String[r];
            Arrays.fill(img, "");
            for (int j = r - 1; j >= 0; j--) {
                String row = s.nextLine();
                for (int k = c - 1; k >= 0; k--) {
                    img[j] += row.charAt(k);
                }
            }

            for (String row : img)
                System.out.println(row);
        }
    }
}