import java.util.Scanner;

public class squarepeg {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        double l = s.nextInt() / 2.0;
        int r = s.nextInt();
        
        System.out.println(Math.sqrt(2 * Math.pow(l, 2)) <= r ? "fits" : "nope");
    }
}