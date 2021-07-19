import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class C {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        double m = sc.nextInt();
        double n = sc.nextInt();
        double res = 0;
        for (int i = 0; i <= m; i++) {
            res += i * Math.pow(i / m, n);
            res -= i * Math.pow((i - 1) / m, n);
        }
        System.out.println(res) ;
    }
}