import java.util.Scanner;

class offworldrecord {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int c = sc.nextInt();
        int p = sc.nextInt();
        int t = 0;
        for (; n > 0; n--) {
            int h = sc.nextInt();
            if (h > c + p) {
                p = c;
                c = h;
                t++;
            }
        }
        System.out.println(t);
    }
}
