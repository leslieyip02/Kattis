import java.util.Scanner;

public class greedypolygons {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for (int i = 0; i < t; i++) {
            int n = s.nextInt();
            int l = s.nextInt();
            int d = s.nextInt();
            int g = s.nextInt();

            double a = 2 * Math.PI / n;
            double r = 0.5 * l  / Math.cos((Math.PI - a) / 2);
            double area = 0.5 * n * Math.pow(r, 2) * Math.sin(a);
            
            area += n * l * d * g;
            area += Math.PI * Math.pow(d * g, 2);
                
            System.out.println(area);
        }
    }
}