import java.util.Scanner;

public class malfunctioningrobot {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();

        while (T > 0) {
            long x1 = s.nextLong();
            long y1 = s.nextLong();
            long x2 = s.nextLong();
            long y2 = s.nextLong();

            long dx = Math.abs(x2 - x1);
            long dy = Math.abs(y2 - y1);
            long z = Math.abs(dx - dy);

            long m = dx + dy + (z / 2 * 2);
            System.out.println(m);

            T--;
        }
    }
}