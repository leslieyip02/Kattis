import java.util.Scanner;
import java.util.ArrayList;

public class schoolspirit {
    public static double score(ArrayList<Integer> students) {
        double cumScore = 0;
        for (int i = 0; i < students.size(); i++)
            cumScore += students.get(i) * Math.pow(0.8, i);
        return cumScore * 0.2;
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();

        ArrayList<Integer> students = new ArrayList<Integer>(n);
        for (int i = 0; i < n; i++)
            students.add(s.nextInt());
        System.out.println(score(students));
        
        double avg = 0;
        for (int i = 0; i < n; i++) {
            ArrayList<Integer> gi = new ArrayList<Integer>(students);
            gi.remove(i);
            avg += score(gi);
        }

        System.out.println(avg / n);
    }
}