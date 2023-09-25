import java.io.*;
import java.util.*;

class gangur {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] sections = br.readLine().split("\\-+");
        long total = 0;

        long left = 0;
        for (int i = 0; i < sections.length; i++) {
            for (int j = 0; j < sections[i].length(); j++) {
                if (sections[i].charAt(j) == '>') {
                    left++;
                } else {
                    total += left;
                }
            }
        }
        System.out.println(total);
    }
}
