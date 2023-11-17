import java.util.*;
import java.util.stream.*;

public class skammstofun {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(
            Stream.generate(sc::next)
                .limit(n)
                .filter(word -> Character.isUpperCase(word.charAt(0)))
                .reduce("", (current, word) -> current + word.charAt(0))
        );
    }
}
