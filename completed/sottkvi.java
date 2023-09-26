import java.util.Scanner;

class sottkvi {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int d = sc.nextInt();
        int c = 0;
        for (; n > 0; n--) {
            int x = sc.nextInt();
            if (14 - (d - x) <= k) {
                c++;
            }
        }
        System.out.println(c);
    }
}
