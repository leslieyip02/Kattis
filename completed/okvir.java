import java.util.Scanner;

public class okvir {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        String[] ln = s.nextLine().split(" ");
        int m = Integer.parseInt(ln[0]);
        int n = Integer.parseInt(ln[1]);
        
        ln = s.nextLine().split(" ");
        int u = Integer.parseInt(ln[0]);
        int l = Integer.parseInt(ln[1]);
        int r = Integer.parseInt(ln[2]);
        int d = Integer.parseInt(ln[3]);

        int h = u + m + d;
        int w = l + n + r;
        char[][] f = new char[h][w];
        for (int i = 0; i < m; i++) {
            String x = s.nextLine();      
            for (int j = 0; j < n; j++)
                f[u + i][l + j] = x.charAt(j);
        }
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++)
                System.out.print(Character.isLetter(f[i][j]) ? f[i][j] : (i + j) % 2 == 0 ? '#' : '.');
            System.out.println();
        }
    }
}