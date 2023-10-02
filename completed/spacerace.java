import java.util.Scanner;

public class spacerace {
    private static double efficiency(double d, double v, double r) {
        return v / (r / (d / v));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt() - 1;
        double d = sc.nextDouble();

        String w = sc.next();
        double v = sc.nextDouble();
        double r = sc.nextDouble();
        double e = efficiency(d, v, r);
        for (; n > 0; n--) {
            String x = sc.next();
            v = sc.nextDouble();
            r = sc.nextDouble();
            double f = efficiency(d, v, r);
            if (f > e) {
                w = x;
                e = f;
            }
        }
        System.out.println(w);
    }
}
