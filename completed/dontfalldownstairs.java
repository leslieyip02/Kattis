import java.io.*;
import java.util.*;

class dontfalldownstairs {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        int p = Integer.parseInt(st.nextToken());
        int E = 0;
        for (int i = 1; i < N; i++) {
            int c = Integer.parseInt(st.nextToken());
            E += Math.max(p - c - 1, 0);
            p = c;
        }
        E += p - 1;
        System.out.println(E);
    }
}
