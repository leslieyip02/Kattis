import java.util.Scanner;

public class loorolls {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        long l = s.nextLong();
        long n = s.nextLong();

        int k = 1;
        while (l % n != 0) {
            n = n - l % n;
            k++;
        }        
        System.out.println(k);
    }
}