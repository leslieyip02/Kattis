import java.util.Scanner;

public class overdraft {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();

        int l = 0;
        int b = 0;
        for (int i = 0; i < n; i++) {
            b += s.nextInt();
            if (b < 0)
                l = Math.min(b, l);
        }

        System.out.println(-l);
    }
}