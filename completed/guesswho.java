import java.util.*;
import java.util.stream.*;

public class guesswho {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int Q = sc.nextInt();
        List<String> attributes = Stream.generate(sc::next)
            .limit(N)
            .collect(Collectors.toList());
        Stream<Integer> ok = Stream.iterate(0, i -> i + 1)
            .limit(N);
        for (int i = 0; i < Q; i++) {
            int A = sc.nextInt();
            char c = sc.next().charAt(0);
            ok = ok.filter(j -> attributes.get(j).charAt(A - 1) == c);
        }

        List<Integer> possible = ok.collect(Collectors.toList());
        if (possible.size() == 1) {
            System.out.println("unique");
            System.out.println(possible.get(0) + 1);
        } else {
            System.out.println("ambiguous");
            System.out.println(possible.size());
        }
    }
}
