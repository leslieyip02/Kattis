import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class endurvinnsla {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String city = br.readLine();
        double p = Double.parseDouble(br.readLine());
        double n = Integer.parseInt(br.readLine());
        int x = 0;
        int y = (int) Math.floor(p * n);
        for (int i = 0; i < n; i++) {
            String item = br.readLine();
            if (item.compareTo("ekki plast") == 0) {
                x++;
            }
        }
        System.out.println(x <= y ? "Jebb" : "Neibb");
    }
}
