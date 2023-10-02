import java.util.Scanner;

class stafur {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String c = sc.next();
        if (c.compareTo("Y") == 0) {
            System.out.println("Kannski");
        } else if (c.compareTo("A") == 0 || c.compareTo("E") == 0 ||
            c.compareTo("I") == 0 || c.compareTo("O") == 0 || c.compareTo("U") == 0) {
            System.out.println("Jebb");
        } else {
            System.out.println("Neibb");
        }
    }
}
