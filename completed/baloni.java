import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class baloni {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int H[] = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            H[i] = Integer.parseInt(st.nextToken());
        }

        int a = 0;
        for (int i = 0; i < n; i++) {
            if (H[i] == -1) {
                continue;
            }

            a++;
            H[i]--;
            for (int j = i + 1; j < n; j++) {
                if (H[j] == H[i]) {
                    H[j] = -1;
                    H[i]--;
                }

                if (H[i] == 0) {
                    break;
                }   
            }
        }

        System.out.println(a);
    }
}
