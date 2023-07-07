import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

public class straights {
    private static int max = (int) 10e4;

    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        int[] f = new int[max + 2];
        StringTokenizer st = new StringTokenizer(br.readLine());
        while (st.hasMoreTokens()) {
            f[Integer.parseInt(st.nextToken())]++;
        }

        int m = 0;
        boolean allZero = false;
        while (!allZero) {
            allZero = true;
            for (int i = 0; i <= max; i++) {
                if (f[i] > 0) {
                    allZero = false;
                    if (f[i + 1] == 0) {
                        m++;
                    }
                    f[i]--;
                }
            }
        }
        System.out.println(m);
    }
}