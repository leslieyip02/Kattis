import java.util.Scanner;

public class simplefactoring {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();

        while (n > 0) {
            long a = s.nextLong();
            long b = s.nextLong();
            long c = s.nextLong();

            long d = b * b - (4 * a * c);
            long e = (int) Math.sqrt(d);
            System.out.println(e * e == d ? "YES" : "NO");

            n--;
        }
    }
}
