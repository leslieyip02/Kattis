import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;

public class keepitcool {
    private static class Pair {
        int value;
        int index;

        public Pair(int value, int index) {
            this.value = value;
            this.index = index;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int s = sc.nextInt();
        int d = sc.nextInt();

        Pair[] c = new Pair[s];
        for (int i = 0; i < s; i++) {
            c[i] = new Pair(sc.nextInt(), i);
        }

        Arrays.sort(c, new Comparator<Pair>() {
            @Override
            public int compare(Pair p1, Pair p2) {
                return p1.value - p2.value;
            }
        });

        int x = 0;
        int y = n;
        int[] z = new int[s];
        while (x < s && y > 0) {
            int w = Math.min(d - c[x].value, y);
            y -= w;
            z[c[x].index] = w;
            x++;
        }

        while (x < s && m > 0) {
            m -= c[x].value;        
            x++;
        }

        if (m > 0) {
            System.out.println("impossible");
        } else {
            for (int i : z) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
}
