import java.util.Scanner;

public class thekeytocryptography {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String ctxt = s.nextLine();
        String key = s.nextLine();

        String msg = "";
        for (int i = 0; i < ctxt.length(); i++) {
            int shift = (int) key.charAt(i);
            int shifted = (int) ctxt.charAt(i);
            char unshifted = (char) ((shifted - shift + 26) % 26 + 65);
            msg += unshifted;
            key += unshifted;
        }
        
        System.out.println(msg);
    }
}