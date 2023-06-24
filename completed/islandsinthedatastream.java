import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class islandsinthedatastream {
    private static int N = 12;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int P = Integer.parseInt(br.readLine());

        int[] seq = new int[N];
        while (P > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int K = Integer.parseInt(st.nextToken());
            for (int i = 0; i < N; i++) {
                seq[i] = Integer.parseInt(st.nextToken());
            }           

            int b = 0;
            for (int i = 1; i < N - 1; i++) {
                for (int j = i; j < N - 1; j++) {
                    boolean ok = true;
                    for (int k = i; k <= j; k++) {
                        if (seq[i - 1] >= seq[k] || seq[j + 1] >= seq[k]) {
                            ok = false;
                            break;
                        }
                    }

                    if (ok) {
                        b++;
                    }
                }
            }

            System.out.println(String.format("%d %d", K, b));

            P--;
        }
    }
}