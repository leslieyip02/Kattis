import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;

public class judgingtroubles {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        HashMap<String, Integer> d = new HashMap<String, Integer>();
        HashMap<String, Integer> k = new HashMap<String, Integer>();

        for (int i = 0; i < n; i++) {
            String r = br.readLine();
            if (!d.containsKey(r)) {
                d.put(r, 0);
            }
            d.put(r, d.get(r) + 1);
        }
        for (int i = 0; i < n; i++) {
            String r = br.readLine();
            if (!k.containsKey(r)) {
                k.put(r, 0);
            }
            k.put(r, k.get(r) + 1);
        }

        HashSet<String> keys = new HashSet<String>(d.keySet());
        for (String i : k.keySet()) {
            keys.add(i);
        }

        int x = 0;
        for (String i : keys) {
            if (d.containsKey(i) && k.containsKey(i)) {
                x += Math.min(d.get(i), k.get(i));
            }
        }
        System.out.println(x);
    }
}