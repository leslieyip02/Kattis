import java.util.*;

public class asciikassi {
    public static void main(String[] args) {
        int N = new Scanner(System.in).nextInt();
        String topEdge = String.format("+%s+", "-".repeat(N));
        String inBetween = String.format("|%s|", " ".repeat(N));
        System.out.println(topEdge);
        for (int i = 0; i < N; i++) {
            System.out.println(inBetween);
        }
        System.out.println(topEdge);
    }
}
