import java.util.Scanner;

public class thelastproblem {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String name = s.nextLine();
        System.out.println(String.format("Thank you, %s, and farewell!", name));
    }
}