import java.util.*;

public class huntthewumpus {
    private static int distanceTo(int target, int guess) {
        return Math.abs(target % 10 - guess % 10) + Math.abs(target / 10 - guess / 10);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int s = sc.nextInt();
        HashMap<Integer, Boolean> w = new HashMap<Integer, Boolean>();
        while (w.size() < 4) {
            s = s + (int) Math.floor(s / 13.0) + 15;
            w.put(s % 100, false);
        }

        int n = 0;
        while (sc.hasNextInt()) {
            int g = sc.nextInt();
            int m = 100;
            for (Integer i : w.keySet()) {
                if (w.get(i)) {
                    continue;
                }

                int d = distanceTo(i, g);
                if (d == 0) {
                    w.put(i, true);
                    System.out.println("You hit a wumpus!");
                } else {
                    m = Math.min(d, m);
                }
            }

            boolean ok = true;
            for (Boolean i : w.values()) {
                ok &= i;
            }
            if (!ok) {
                System.out.println(m);
            }
            n++;
        }
        System.out.println(String.format("Your score is %d moves.", n));
    }
}
