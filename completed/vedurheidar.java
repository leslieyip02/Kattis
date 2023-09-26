import java.util.Scanner;

class vedurheidar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int v = sc.nextInt();
        int n = sc.nextInt();
        for (; n > 0; n--) {
            String s = sc.next();
            int k = sc.nextInt();
            System.out.println(String.format("%s %s", s, v <= k ? "opin" : "lokud"));
        }
    }
}
