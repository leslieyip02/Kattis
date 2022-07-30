import java.util.Scanner;

public class rijeci {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k = Integer.parseInt(scanner.nextLine());
        int a = 1;
        int b = 0;
        
        for (int i = 0; i < k; i++) {
            int ai = a;
            a = b;
            b += ai;
        }
        
        System.out.println(String.format("%d %d", a, b));
    }
}