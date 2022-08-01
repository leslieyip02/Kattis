import java.util.Scanner;

public class drunkvigenere {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String encrypted = s.nextLine();
        String key = s.nextLine();
        String msg = "";

        for (int i = 1; i <= encrypted.length(); i++) {
            int shift = key.charAt(i - 1) - 65;
            int shifted = (encrypted.charAt(i - 1) - 65) + (i % 2 == 0? shift : - shift);
            msg += (char) ((shifted + 26) % 26 + 65);
        }
        System.out.println(msg);
    }
}