import java.util.*;

class Value {
    public int v, i, j;
    public Value(int v, int i) {
        this.v = v;
        this.i = i;
    }
}

public class synchronizinglists {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        while (n != 0) {
            Value[] list1 = new Value[n];
            for (int i = 0; i < n; i++)
                list1[i] = new Value(s.nextInt(), i);
            Arrays.sort(list1, (x, y) -> (x.v == y.v) ? 0 : (x.v > y.v) ? 1 : -1);
            
            for (int j = 0; j < n; j++)
                list1[j].j = j;
            Arrays.sort(list1, (x, y) -> (x.i > y.i) ? 1 : -1);
            
            int[] list2 = new int[n];
            for (int i = 0; i < n; i++) 
                list2[i] = s.nextInt();
            Arrays.sort(list2);
            
            for (Value v : list1)
                System.out.println(list2[v.j]); 
            System.out.println();
            n = s.nextInt();
        }
    }
}