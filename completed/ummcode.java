import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.stream.Collectors;

public class ummcode {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        ArrayList<Integer> b = new ArrayList<Integer>();
        while (st.hasMoreTokens()) {
            String t = st.nextToken();

            boolean um = true;
            for (int i = 0; i < t.length(); i++) {
                if (!Character.isLetterOrDigit(t.charAt(i))) {
                    continue;
                }
                if (t.charAt(i) != 'u' && t.charAt(i) != 'm') {
                    um = false;
                    break;
                }
            }

            if (um) {
                for (int i = 0; i < t.length(); i++) {
                    if (!Character.isLetterOrDigit(t.charAt(i))) {
                        continue;
                    }
                    b.add(t.charAt(i) == 'u' ? 1 : 0);
                }
            }
        }

        for (int i = 0; i < b.size(); i += 7) {
            String s = b.subList(i, i + 7).stream().map(String::valueOf).collect(Collectors.joining(""));
            System.out.print((char) Integer.parseInt(s, 2));
        }
        System.out.println();
    }
}