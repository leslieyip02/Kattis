import java.util.Scanner;

class bannord {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();

        while (sc.hasNext()) {
            String w = sc.next();
            boolean ok = true;
            for (int i = 0; i < S.length(); i++) {
                if (w.indexOf(S.charAt(i)) != -1) {
                    ok = false;
                    break;
                } 
            }
            System.out.println(ok ? w : "*".repeat(w.length()));
        }
    }
}
