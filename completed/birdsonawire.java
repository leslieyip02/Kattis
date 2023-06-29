import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

public class birdsonawire {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int l = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        int[] w = new int[n + 2];
        for (int i = 0; i < n; i++) {
            w[i] = Integer.parseInt(br.readLine());
        }

        w[n] = 0;
        w[n + 1] = l;
        Arrays.sort(w);     

        int b = 0;
        if (w[1] - 6 >= d) {
            w[0] = 6;
            b++;
        } else {
            w[0] = w[1];
        }
        if (l - 6 - w[n] >= d) {
            w[n + 1] = l - 6;
            b++;
        } else {
            w[n + 1] = w[n];
        }

        for (int i = 0; i < n + 1; i++) {
            b += Math.max((w[i + 1] - w[i]) / d - 1, 0);
        }

        System.out.println(b);
    }
}