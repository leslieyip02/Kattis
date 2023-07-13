import java.util.Scanner;

public class lektira {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String w = sc.nextLine();

        int n = w.length();
        String b = "z".repeat(n);
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                StringBuilder sb = new StringBuilder();
                for (int k = i - 1; k >= 0; k--) {
                    sb.append(w.charAt(k));
                }
                for (int k = j - 1; k >= i; k--) {
                    sb.append(w.charAt(k));
                }
                for (int k = n - 1; k >= j; k--) {
                    sb.append(w.charAt(k));
                }

                String s = sb.toString();
                if (s.compareTo(b) < 0) {
                    b = s;
                }
            }
        }
        System.out.println(b);
    }
}