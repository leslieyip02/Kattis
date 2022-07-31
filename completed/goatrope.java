import java.util.Scanner;

public class goatrope {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int x = s.nextInt();
        int y = s.nextInt();
        int x1 = s.nextInt();
        int y1 = s.nextInt();
        int x2 = s.nextInt();
        int y2 = s.nextInt();

        int x0 = Math.abs(x1 - x) < Math.abs(x2 - x) ? x1 : x2;
        int y0 = Math.abs(y1 - y) < Math.abs(y2 - y) ? y1 : y2;

        if (x > x1 && x < x2)
            System.out.println(y0 == y1 ? Math.abs(y1 - y) :  Math.abs(y2 - y));
        else if (y > y1 && y < y2)
            System.out.println(x0 == x1 ? Math.abs(x1 - x) :  Math.abs(x2 - x));
        else 
            System.out.println(Math.sqrt(Math.pow(x0 - x, 2) + Math.pow(y0 - y, 2)));
    }
}