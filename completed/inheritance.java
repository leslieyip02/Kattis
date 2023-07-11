import java.util.Scanner;
import java.util.TreeSet;

public class inheritance {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        long P = Long.parseLong(s);
        int n = s.length();
        TreeSet<Long> k = new TreeSet<Long>();
        for (int i = 1; i < (1 << n); i++) {
            int j = i;
            StringBuilder sb1 = new StringBuilder();
            StringBuilder sb2 = new StringBuilder();
            while (j > 0) {
                sb1.append((j & 1) == 0 ? 2 : 4);
                sb2.append((j & 1) == 0 ? 4 : 2);
                j >>= 1;
            }
            k.add(Long.parseLong(sb1.toString()));
            k.add(Long.parseLong(sb2.toString()));
        }

        for (long i : k) {
            if (P % i == 0) {
                System.out.println(i);
            }
        }
    }
}