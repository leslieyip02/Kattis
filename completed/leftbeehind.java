import java.util.Scanner;

public class leftbeehind {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int x = s.nextInt();
        int y = s.nextInt();

        while (!(x == 0 && y == 0)) {
            if (x + y == 13)
                System.out.println("Never speak again.");
            else if (y > x)
                System.out.println("Left beehind.");
            else if (y == x)
                System.out.println("Undecided.");
            else 
                System.out.println("To the convention.");

            x = s.nextInt();
            y = s.nextInt();
        }
    }
}