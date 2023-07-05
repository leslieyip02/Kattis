import java.util.Scanner;
import java.util.StringTokenizer;

public class nizovi {
    public static void indent(int depth) {
        System.out.print(" ".repeat(depth * 2));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.nextLine();

        int depth = 0;
        boolean needToIndent = false;
        StringTokenizer st = new StringTokenizer(S, ",");
        while (st.hasMoreTokens()) {
            String s = st.nextToken();

            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                if (c == '{') {
                    indent(depth++);
                    System.out.println(c);
                    needToIndent = true;
                } else if (c == '}') {
                    if (s.charAt(i - 1) != '{') {
                        System.out.println();
                    }
                    indent(--depth);
                    System.out.print(c);
                    needToIndent = true;
                } else {
                    if (needToIndent) {
                        indent(depth);
                        needToIndent = false;
                    }
                    System.out.print(c);
                }
            }

            if (st.hasMoreTokens()) {
                System.out.print(",");
            }
            System.out.println();
            needToIndent = true;
        }
    }
}