import java.util.Scanner;

public class soylent {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();

        while (t-- > 0) 
            System.out.println((int) Math.ceil(s.nextInt() / 400.0));
    }
}