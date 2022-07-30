import java.util.Scanner;

interface IShape {
    public boolean contains(int x0, int y0);
}
    
class Rectangle implements IShape {
    public int x1, y1, x2, y2;
        
    public Rectangle(String[] params) {
        this.x1 = Integer.parseInt(params[1]);
        this.y1 = Integer.parseInt(params[2]);
        this.x2 = Integer.parseInt(params[3]);
        this.y2 = Integer.parseInt(params[4]);
    }
        
    public boolean contains(int x0, int y0) {
        return (x0 >= this.x1 && x0 <= this.x2) && 
            (y0 >= this.y1 && y0 <= this.y2);
    }
}

class Circle implements IShape {
    public int x, y, r;
            
    public Circle(String[] params) {
        this.x = Integer.parseInt(params[1]);
        this.y = Integer.parseInt(params[2]);
        this.r = Integer.parseInt(params[3]);
    }
            
    public boolean contains(int x0, int y0) {
        return Math.sqrt(Math.pow(x0 - this.x, 2) + Math.pow(y0 - this.y, 2)) <= this.r;
    }
}

public class hittingthetargets {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int m = Integer.parseInt(scanner.nextLine());
        IShape[] shapes = new IShape[m];
        for (int i = 0; i < m; i++) {
            String[] shape = scanner.nextLine().split(" ", 5);
            shapes[i] = (shape[0].equals("rectangle"))? new Rectangle(shape) : new Circle(shape);
        }
        
        int n = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < n; i++) {
            int x0 = scanner.nextInt();
            int y0 = scanner.nextInt();
            
            int hits = 0;
            for (IShape shape : shapes) {
                if (shape.contains(x0, y0))
                    hits++;
            }
            System.out.println(hits);
        }
    }
}