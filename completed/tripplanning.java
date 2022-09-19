import java.util.Scanner;

public class tripplanning {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        
        int n = s.nextInt();
        int m = s.nextInt();
        
        int[] r = new int[n];
        for (int i = 1; i <= m; i++) {
            int a = s.nextInt();
            int b = s.nextInt();
            
            if (a > b) {
                int c = a;
                a = b;
                b = c;
            }

            if (a == 1 && b == n) {
                r[n - 1] = i;
            }
            
            if (b - a == 1) {
                r[a - 1] = i;
            }
        }

        boolean p = true;
        for (int i : r) {
            if (i == 0) {
                p = false;
                break;
            }
        }
        
        if (p) {
            for (int i : r)
                System.out.println(i);
        } else {
            System.out.println("impossible");
        }
    }
}