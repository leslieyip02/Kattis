import java.util.Scanner;

public class averagecharacter {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String str = s.nextLine();

        int val = 0;
        for (int i = 0; i < str.length(); i++)
            val += str.charAt(i);
        System.out.println((char) (val / str.length()));
    }
}