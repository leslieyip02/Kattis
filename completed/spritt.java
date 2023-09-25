import java.util.Scanner;

class spritt {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int x = sc.nextInt();
        for (; n > 0; n--) {
            x -= sc.nextInt();
            if (x < 0) {
                break;
            }
        }
        System.out.println(x < 0 ? "Neibb" : "Jebb");
    }
}