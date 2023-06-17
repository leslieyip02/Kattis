import java.util.Scanner;

public class pebblesolitaire {
    private static int length = 12;

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String line = s.nextLine();

        int n = Integer.parseInt(line);
        while (n > 0) {
            line = s.nextLine();
            System.out.println(move(line));
            n--;
        }
    }

    public static int move(String line) {
        int pebbles = 0;
        for (int i = 0; i < length; i++) {
            if (line.charAt(i) == 'o') {
                pebbles++;
            }
        }

        int minimumPebbles = pebbles;
        for (int i = 0; i < length; i++) {
            if (line.charAt(i) == '-') {
                continue;
            }
            
            // forward
            if (i < length - 2 &&
                line.charAt(i + 1) == 'o' &&
                line.charAt(i + 2) == '-') {
                
                String newLine = line.substring(0, i)
                    + "--o" + line.substring(i + 3);
                int newPebbles = move(newLine);
                if (newPebbles < minimumPebbles) {
                    minimumPebbles = newPebbles;
                }
            }

            // backward
            if (i >= 2 &&
                line.charAt(i - 1) == 'o' &&
                line.charAt(i - 2) == '-') {
                
                String newLine = line.substring(0, i - 2)
                    + "o--" + line.substring(i + 1);
                int newPebbles = move(newLine);
                if (newPebbles < minimumPebbles) {
                    minimumPebbles = newPebbles;
                }
            }
        }

        return minimumPebbles;
    }
}