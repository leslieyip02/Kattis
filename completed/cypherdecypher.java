import java.util.Scanner;

class cypherdecypher {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String m = sc.next();
        int n = sc.nextInt();
        int l = m.length();
        int[] v = new int[l];
        for (int i = 0; i < l; i++) {
            v[i] = Character.getNumericValue(m.charAt(i));
        }
        for (; n > 0; n--) {
            String s = sc.next();
            for (int i = 0; i < l; i++) {
                int k = ((int) s.charAt(i) - 65) * v[i];
                System.out.print((char) ((k % 26) + 65));
            }
            System.out.println();
        }
    }
}
