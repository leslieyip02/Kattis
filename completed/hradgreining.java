import java.util.Scanner;

public class hradgreining {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = sc.next();
        System.out.println(line.contains("COV") ? "Veikur!" : "Ekki veikur!");
    }
}
