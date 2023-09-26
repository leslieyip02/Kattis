import java.util.Scanner;

class ullendullendoff {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = n >= 13 ? 12 : 13 % n - 1;
        String s = sc.next();
        for (; m > 0; m--) {
            s = sc.next();
        }
        System.out.println(s);
    }
}