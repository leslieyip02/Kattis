import java.util.Scanner;
import java.util.ArrayList;
import java.util.StringTokenizer;

class ekkidaudi {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<String> front = new ArrayList<>();
        ArrayList<String> back = new ArrayList<>();
        while (sc.hasNext()) {
            String[] halves = sc.nextLine().split("\\|");
            front.add(halves[0]);
            back.add(halves[1]);
        }
        for (String s : front) {
            System.out.print(s);
        }
        System.out.print(" ");
        for (String s : back) {
            System.out.print(s);
        }
        System.out.println();
    }
}