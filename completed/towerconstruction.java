import java.util.Scanner;

public class towerconstruction {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int w = 0;
        int c = 0;
        for (int i = 0; i < n; i++) {
            int x = s.nextInt();
            if (x > w) 
                c++;
            w = x;
        }
        
        System.out.println(c);
    }
}