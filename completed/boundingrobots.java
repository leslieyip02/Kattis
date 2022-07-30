    import java.util.Scanner;

    public class boundingrobots {
        public static void main(String[] args) {
            Scanner s = new Scanner(System.in);
            int w = s.nextInt();
            int l = s.nextInt();
            
            while (w != 0 && l != 0) {
                int n = s.nextInt();
                int x0 = 0, y0 = 0, x1 = 0, y1 = 0;
                for (int i = 0; i < n; i++) {
                    String dir = s.next();
                    int d = s.nextInt();

                    if (dir.equals("u")) {
                        y0 += d;
                        y1 = Math.min(y1 + d, l - 1);
                    } else if (dir.equals("d")) {
                        y0 -= d;
                        y1 = Math.max(y1 - d, 0);
                    } else if (dir.equals("l")) {
                        x0 -= d;
                        x1 = Math.max(x1 - d, 0);
                    } else {
                        x0 += d;
                        x1 = Math.min(x1 + d, w - 1);
                    }
                }

                System.out.println(String.format("Robot thinks %d %d", x0, y0));
                System.out.println(String.format("Actually at %d %d\n", x1, y1));
                
                w = s.nextInt();
                l = s.nextInt();
            }
        }
    }