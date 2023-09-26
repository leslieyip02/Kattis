import java.util.Scanner;
import java.util.HashSet;

class hvertskalmaeta {
    public static void main(String[] args) {
        HashSet<String> a = new HashSet<>();
        a.add("Akureyri");
        a.add("Fjardabyggd");
        a.add("Mulathing");
        Scanner sc = new Scanner(System.in);
        System.out.println(a.contains(sc.next()) ? "Akureyri" : "Reykjavik");
    }
}