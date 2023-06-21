import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

public class roompainting {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] sizes = new int[n];
        for (int i = 0; i < n; i++) {
            sizes[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(sizes);

        long total = 0;
        for (int i = 0; i < m; i++) {
            int needed = Integer.parseInt(br.readLine());
            if (needed == 0) {
                continue;
            }

            int lo = 0;
            int hi = n - 1;
            int mid = (lo + hi) / 2;
            while (lo <= hi) {
                mid = (lo + hi) / 2;

                if (sizes[mid] == needed) {
                    break;              
                } else if (sizes[mid] < needed) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            while (sizes[mid] < needed) {
                mid++;
            }
            total += sizes[mid] - needed;
        }

        System.out.println(total);
    }
}
