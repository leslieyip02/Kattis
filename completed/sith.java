import java.util.Scanner;

class sith {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name = sc.nextLine();
        int a = Integer.parseInt(sc.nextLine());
        int b = Integer.parseInt(sc.nextLine());
        int x = Integer.parseInt(sc.nextLine());
        System.out.println(x < 0 ? "JEDI" : a < b ? "SITH" : "VEIT EKKI");
    }
}
