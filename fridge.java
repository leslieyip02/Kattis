import java.util.Scanner;

public class fridge {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String line = sc.nextLine();

	int[] d = new int[10];
	for (int i = 0; i < line.length(); i++) {
	    d[Character.getNumericValue(line.charAt(i))]++;
	}

	int min = 1;
	for (int i = 0; i < 10; i++) {
	    if (d[i] < d[min]) {
		min = i;
	    }
	}

	String o = String.valueOf(min).repeat(d[min] + 1);
	if (min == 0) {
	    for (int i = 1; i < 10; i++) {
		if (d[i] > 0) {
		    o = String.valueOf(i) + o;
		    break;
		}
	    }
	}

	System.out.println(o);
    }
}
