import java.util.Scanner;

public class basketballoneonone {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String game = s.nextLine();

        int a = 0;
        int b = 0;
        for (int i = 0; i < game.length(); i += 2) {
            if (game.charAt(i) == 'A')
                a += game.charAt(i + 1) - '0';
            else
                b += game.charAt(i + 1) - '0';
                
            if (a >= 10 && b >= 10) {
                if (a - b >= 2) {
                    System.out.println('A');
                    break;
                } else if (b - a >= 2) {
                    System.out.println('B');
                    break;
                }
            } else {
                if (a >= 11) {
                    System.out.println('A');
                    break;
                } else if (b >= 11) {
                    System.out.println('B');
                    break;
                }
            }
        }
    }
}