import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class leftandright {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String seq = br.readLine() + "R";

        int left = 1;
        for (int right = 1; right <= n; right++) {
            if (seq.charAt(right - 1) == 'R') {
                System.out.println(right);
                for (int j = right - 1; j >= left; j--) {
                    System.out.println(j);
                }
                left = right + 1;
            }
        }
    }
}