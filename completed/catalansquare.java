import java.util.Scanner;
import java.math.BigInteger;

public class catalansquare {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt() + 1;

        // Sn = C(n + 1)
        // expand C(n + 1) and its factorials to get rid of redundant terms
        BigInteger sum = new BigInteger("1");
        for (int i = 0; i < n; i++)
            sum = sum.multiply(new BigInteger(i % 2 == 0 ? "2" : (2 * n - i) + ""));

        for (int i = 2; i <= n / 2; i++)
            sum = sum.divide(new BigInteger(i + ""));

        System.out.println(sum.divide(new BigInteger((n + 1) + "")));
    }
}