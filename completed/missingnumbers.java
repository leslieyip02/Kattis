import java.util.Scanner;

public class missingnumbers {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        
        int prev = 0;
        boolean missed = false;
        for (int i = 0; i < n; i++) {
            int x = s.nextInt();
            if (x - 1 != prev) {
                missed = true;
                while (prev < x - 1) {
                    prev++;
                    System.out.println(prev);
                }
            }
            prev = x;
        }

        if (!missed)
            System.out.println("good job");
    }
}