import java.util.Scanner;

public class licensetolaunch {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        
        int n = s.nextInt();
        int dMin = -1;
        int iMin = -1;
        for (int i = 0; i < n; i++) {
            int d = s.nextInt();
            if (d < dMin || dMin == -1) {
                dMin = d;
                iMin = i;
            }
        }
        System.out.println(iMin);
    }
}