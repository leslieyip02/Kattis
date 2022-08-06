import java.util.Scanner;

public class scalingrecipe {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        double x = (double) s.nextInt();
        double y = (double) s.nextInt();

        for (int i = 0; i < n; i++)
            System.out.println((int) (s.nextInt() * y / x));
    }
}