import java.util.Scanner;
import java.util.HashMap;

public class securedoors {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = Integer.parseInt(s.nextLine());

        HashMap<String, Boolean> log = new HashMap<String, Boolean>();
        for (int i = 0; i < n; i++) {
            String[] line = s.nextLine().split(" ", 2);
            if (line[0].equals("entry")) {
                System.out.println(String.format("%s entered %s", line[1],
                    !log.getOrDefault(line[1], false) ? "" : "(ANOMALY)"));
                log.put(line[1], true); 
            } else {
                System.out.println(String.format("%s exited %s", line[1],
                    log.getOrDefault(line[1], false) ? "" : "(ANOMALY)"));
                log.put(line[1], false); 
            }
        }
    }
}