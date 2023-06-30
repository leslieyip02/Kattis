import java.util.Scanner;

public class factstonebenchmark {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);

	int y = Integer.parseInt(sc.nextLine());
	while (y != 0) {
	    // 2^m >= n!
	    // m log(2) >= log(n) + log(n - 1) + ...
	    int m = (y / 10 - 196) + 2;
	    double a = (1 << m) * Math.log(2);
	    
	    int n = 3;
	    double b = Math.log(2) + Math.log(3);

	    while (true) {
		b += Math.log(n + 1);
		if (b > a) {
		    break;
		}
		n++;
	    }

	    System.out.println(n);
	    y = Integer.parseInt(sc.nextLine());
	}
    }
}
