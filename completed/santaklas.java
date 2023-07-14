import java.util.Scanner;

public class santaklas {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int v = sc.nextInt();

        if (v <= 180) {
            System.out.println("safe");
        } else {
            double a = (v <= 270 ? v - 180 : 360 - v) / 180.0 * Math.PI;
            System.out.println((int) (H / Math.sin(a)));
        }
    }
}