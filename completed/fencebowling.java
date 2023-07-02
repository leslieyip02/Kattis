import java.util.Scanner;

public class fencebowling {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int w = sc.nextInt();
        int l = sc.nextInt();

        double lo = 0.0;
        double hi = Math.PI / 2;
        double b = (lo + hi) / 2;
        double y = 0.0;
        while (Math.abs(y - l) >= 10e-7) {
            b = (lo + hi) / 2;

            y = (w / 2.0) * Math.tan(b);
            for (int i = 1; i < k; i++) {
                y += (1 << i) * w * Math.tan(b);
            }
            y += (1 << k) * (w / 2.0) * Math.tan(b);

            if (y > l) {
                hi = b;
            } else {
                lo = b;
            }
        }

        System.out.println(b * 180 / Math.PI);
    }
}