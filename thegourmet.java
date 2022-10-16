import java.util.Scanner;

public class thegourmet {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int m = sc.nextInt();
        int n = sc.nextInt();

        int[] c = new int[n];
        for (int i = 0; i < n; i++)
            c[i] = sc.nextInt();

        int[] t = new int[m + 1];
        t[0] = 1;
        for (int i = 1; i <= m; i++)
            for (int j : c)
                if (j <= i)
                    t[i] += t[i - j];
                    
        System.out.println(t[m]);
    }
}