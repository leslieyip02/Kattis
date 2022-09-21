import java.util.Scanner;
import java.util.stream.Stream;

public class sumoftheothers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextLine()) {
            int[] n = Stream.of(sc.nextLine().split(" "))
                .mapToInt(Integer::parseInt)
                .toArray();

            for (int i = 0; i < n.length; i++) {
                int s = 0;
                for (int j = 0; j < n.length; j++)
                    if (i != j)
                        s += n[j];

                if (s == n[i]) {
                    System.out.println(s);
                    break;
                }
            }
        }
    }
}