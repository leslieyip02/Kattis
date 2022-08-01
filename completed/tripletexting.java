import java.util.Scanner;

public class tripletexting {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String text = s.nextLine();
        String msg1 = text.substring(0, text.length() / 3);
        String msg2 = text.substring(text.length() / 3, 2 * text.length() / 3);
        String msg3 = text.substring(2 * text.length() / 3);
        System.out.println(msg1.equals(msg2) ? msg1 : msg2.equals(msg3) ? msg2 : msg1);
    }
}