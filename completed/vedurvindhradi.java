import java.io.*;
import java.util.*;

class vedurvindhradi {
    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);
        double wind = sc.nextDouble();
        System.out.println(wind <= 0.2
            ? "Logn" : wind <= 1.5
            ? "Andvari" : wind <= 3.3
            ? "Kul" : wind <= 5.4
            ? "Gola" : wind <= 7.9
            ? "Stinningsgola" : wind <= 10.7
            ? "Kaldi" : wind <= 13.8
            ? "Stinningskaldi" : wind <= 17.1
            ? "Allhvass vindur" : wind <= 20.7
            ? "Hvassvidri" : wind <= 24.4
            ? "Stormur" : wind <= 28.4
            ? "Rok" : wind <= 32.6
            ? "Ofsavedur" : "Farvidri");
    }
}
