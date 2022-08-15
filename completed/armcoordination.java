import java.util.Scanner;

public class armcoordination {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int x = s.nextInt();
        int y = s.nextInt();
        int r = s.nextInt();

        int[][] order = {{ 1, 1 }, { 1, -1 }, { -1, -1 }, { -1, 1 }};
        for (int[] o : order)
            System.out.printf("%d %d\n", x + r * o[0], y + r * o[1]);
    }
}