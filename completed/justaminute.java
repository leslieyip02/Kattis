import java.util.Scanner;

public class justaminute {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();

        int min = 0;
        int sec = 0;
        for (int i = 0; i < n; i++) {
            min += s.nextInt();
            sec += s.nextInt();
        }

        double len = sec / (min * 60.0);
        System.out.println(len <= 1 ? "measurement error" : len);
    }
}