import java.util.Scanner;
import java.util.Stack;

public class gameofthrowns {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int k = s.nextInt();

        Stack<Integer> e = new Stack<Integer>();
        e.push(0);

        while (k > 0) {
            String c = s.next();
            if (c.equals("undo")) {
                int m = s.nextInt();
                for (int i = 0; i < m; i++) {
                    e.pop();
                }
            } else {
                int p = Integer.parseInt(c);
                e.push(((e.peek() + p) % n + n) % n);
            }

            k--;
        }

        System.out.println(e.pop());
    }
}