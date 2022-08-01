import java.util.Scanner;

public class mult {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();

        int si = -1;
        for (int i = 0; i < n; i++) {
            int c = s.nextInt();
            if (si == -1) {
                si = c;
            } else {
                if (c % si == 0) {
                    System.out.println(c);
                    si = -1;
                }
            }
        }
    }
}