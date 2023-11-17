import java.util.*;
import java.util.stream.*;

public class cornhusker {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int sum = Stream.generate(() -> sc.nextInt() * sc.nextInt())
            .limit(5)
            .reduce(0, (x, y) -> x + y);
        int n = sc.nextInt();
        int kwf = sc.nextInt();
        System.out.println(sum / 5 * n / kwf);
    }
}
