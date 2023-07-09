import java.util.Scanner;

public class base2palindromes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int M = sc.nextInt();

        if (M <= 2) {
            System.out.println(M == 1 ? 1 : 3);
        } else {
            int n = 1;
            int x = 1;
            while (M > x) {
                for (int i = 0; i < 2; i++ ) {
                    M -= x;
                    n++;
                    if (x >= M) {
                        break;
                    }
                }
                x *= 2;
            }

            String s = Integer.toBinaryString(M - 1);
            while (s.length() < (n - 1) / 2) {
                s = "0" + s;
            }
            StringBuilder sb = new StringBuilder();
            sb.append("1");
            sb.append(s);

            int start = (n % 2 == 0) ? (s.length() - 1) : (s.length() - 2);
            for (int i = start; i >= 0; i--) {
                sb.append(s.charAt(i));
            }
            sb.append("1");
            System.out.println(Integer.parseInt(sb.toString(), 2));
        }
    }
}