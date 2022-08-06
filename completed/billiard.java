import java.util.Scanner;

public class billiard {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int s = scanner.nextInt();
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        
        while (a != 0 && b!= 0 && s != 0 && m != 0 && n != 0) {
            double x = a * m;
            double y = b * n;
            
            System.out.println(String.format("%.2f %.2f", Math.atan(y / x) / Math.PI * 180,
                Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2)) / s));

            a = scanner.nextInt();
            b = scanner.nextInt();
            s = scanner.nextInt();
            m = scanner.nextInt();
            n = scanner.nextInt();
        }
    }
}