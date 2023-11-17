import java.util.*;
import java.util.stream.*;

public class prjonamynstur {
    public static void main(String[] args) {
        HashMap<Integer, Integer> cost = new HashMap<>();
        cost.put((int) '.', 20);
        cost.put((int) 'O', 10);
        cost.put((int) '\\', 25);
        cost.put((int) '/', 25);
        cost.put((int) 'A', 35);
        cost.put((int) '^', 5);
        cost.put((int) 'v', 22);

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        System.out.println(
            Stream.generate(sc::next)
                .limit(n)
                .flatMap(row -> row.chars()
                    .mapToObj(cost::get)
                )
                .reduce(0, (x, y) -> x + y)
        );
    }
}
