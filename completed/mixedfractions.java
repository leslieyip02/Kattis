import java.util.Scanner;

public class mixedfractions {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int y = scanner.nextInt(); 
        
        while (x != 0 && y != 0) {
            int a = x / y;
            System.out.println(String.format("%d %d / %d", a, x - a * y, y));
        
            x = scanner.nextInt();
            y = scanner.nextInt();
        }
    }
}