import java.util.Scanner;

class mylla {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] g = new String[3];
        for (int i = 0; i < 3; i++) {
            g[i] = sc.nextLine();
            if (g[i].compareTo("OOO") == 0) {
                System.out.println("Jebb");
                return;
            }
        }

        for (int i = 0; i < 3; i++) {
            int o = 0;
            for (int j = 0; j < 3; j++) {
                if (g[j].charAt(i) == 'O') {
                    o++;
                }
            }
            if (o == 3) {
                System.out.println("Jebb");
                return;
            }
        }
        
        if ((g[0].charAt(0) == 'O' && g[1].charAt(1) == 'O' && g[2].charAt(2) == 'O') ||
            (g[0].charAt(2) == 'O' && g[1].charAt(1) == 'O' && g[2].charAt(0) == 'O')) {
            System.out.println("Jebb");
            return;
        }
        System.out.println("Neibb");
    }
}