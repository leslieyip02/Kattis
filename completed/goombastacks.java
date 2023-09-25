import java.util.Scanner;

class goombastacks {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int s = 0;
        for (; N > 0; N--) {
            s += sc.nextInt();
            int b = sc.nextInt();
            if (s < b) {
                System.out.print("im");
                break;
            }
        }
        System.out.println("possible");
    }
}