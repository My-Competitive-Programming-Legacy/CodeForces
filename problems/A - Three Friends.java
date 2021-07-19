//;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        while(q--  > 0 ){
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            int res = Math.abs(a -b) + Math.abs(c -b) +Math.abs(a -c);
            System.out.println(Math.max(res-4 , 0));


        }
    }
}