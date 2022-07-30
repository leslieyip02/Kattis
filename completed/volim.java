import java.util.Scanner;

public class volim {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k = Integer.parseInt(scanner.nextLine());
        int n = Integer.parseInt(scanner.nextLine());

        int t = 0;
        for (int i = 0; i < n; i++) {
            String[] line = scanner.nextLine().split(" ", 2);
            t += Integer.parseInt(line[0]);

            if (t >= 210)
                break;

            String z = line[1];
            if (z.equals("T"))
                k = k == 8 ? 1 : k + 1;
        }
        
        System.out.println(k);
    }
}