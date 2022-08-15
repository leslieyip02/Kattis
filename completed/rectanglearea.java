import java.util.Scanner;

public class rectanglearea {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        double x1 = s.nextDouble();
        double y1 = s.nextDouble();
        double x2 = s.nextDouble();
        double y2 = s.nextDouble();

        System.out.println(Math.abs(x1 - x2) * Math.abs(y1 - y2));
    }
}