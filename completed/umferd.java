import java.util.*;

public class umferd {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        double empty = 0.0;
        for (int i = 0; i < n; i++) {
            String row = sc.next();
            for (int j = 0; j < m; j++) {
                if (row.charAt(j) == '.') {
                    empty++;
                }
            }
        }
        System.out.println(empty / (m * n));
    }
}
