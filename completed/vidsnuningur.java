import java.util.Scanner;

public class vidsnuningur {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = sc.next();
        for (int i = line.length() - 1; i >= 0; i--) {
            System.out.print(line.charAt(i));
        }
        System.out.println();
    }
}
