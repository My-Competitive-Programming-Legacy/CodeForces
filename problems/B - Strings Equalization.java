import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    static long MOD = (long) 1e9 + 7;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        sc.nextLine();
        outer: while (q-- > 0) {
            char[] a = sc.nextLine().toCharArray();
            char[] b = sc.nextLine().toCharArray();
            if(a.length != b.length)
            {
                System.out.println("NO");
                continue ;
            }
            int[]set = new int[27];
            for (int i = 0; i <a.length ; i++) {
                set[(a[i] - 'a')] = 1;
            }
            for (int i = 0; i <b.length ; i++) {
               if(set[b[i] - 'a'] == 1)
               {
                   System.out.println("YES");
                   continue outer;
               }
            }
            System.out.println("NO");

        }

    }
}