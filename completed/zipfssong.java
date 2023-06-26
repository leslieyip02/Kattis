import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.util.Comparator;

public class zipfssong {
    private static class Song {
        String name;
        long q;

        public Song(String name, long q) {
            this.name = name;
            this.q = q;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        Song[] s = new Song[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            long f = Long.parseLong(st.nextToken());
            long q = f * (i + 1);
            String name = st.nextToken();
            s[i] = new Song(name, q);
        }

        Arrays.sort(s, new Comparator<Song>() {
            @Override
            public int compare(Song s1, Song s2) {
                return (int) Math.signum(s2.q - s1.q);
            }
        });

        for (int i = 0; i < m; i++) {
            System.out.println(s[i].name);
        }
    }
}