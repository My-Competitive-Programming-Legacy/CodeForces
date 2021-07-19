import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out) ;
       int n =  sc.nextInt();
        int m = sc.nextInt();
        sc.nextLine() ;
        String[] f = sc.nextLine().split(" ");
        String[] l = sc.nextLine().split(" ");
        int q = sc.nextInt();
        for(int i = 0 ; i <q ; ++i) {
            int a = sc.nextInt()-1 ;
            out.println(f[a%n] + l[a%m]) ;
        }
        out.flush();


    }
}