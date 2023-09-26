import java.io.*;
import java.util.*;

class vefthjonatjon {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] c = { 0, 0, 0 };
        for (; n > 0; n--) {
            String[] s = br.readLine().split(" ");
            for (int i = 0; i < 3; i++) {
                if (s[i].compareTo("J") == 0) {
                    c[i]++;
                }
            }
        }
        System.out.println(Math.min(c[0], Math.min(c[1], c[2])));
    }
}
