import java.util.Scanner;

public class bus {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for (int i = 0; i < t; i++) {
            int k = s.nextInt();
            double p = 0;
            for (int j = 0; j < k; j++) {
                p += 0.5;
                p *= 2;
            }
            System.out.println((int) p);
        }
    }
}