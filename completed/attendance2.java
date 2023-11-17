import java.io.*;
import java.util.*;

public class attendance2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        List<String> absentees = new ArrayList<>();
        String previous = br.readLine().trim();
        for (int i = 1; i < N; i++) {
            String current = br.readLine().trim();
            if (previous.compareTo("Present!") != 0 && current.compareTo("Present!") != 0) {
                absentees.add(previous);
            }
            previous = current;
        }
        if (previous.compareTo("Present!") != 0) {
            absentees.add(previous);
        }
        if (absentees.isEmpty()) {
            System.out.println("No Absences");
        } else {
            for (String absentee : absentees) {
                System.out.println(absentee);
            }
        }
    }
}
