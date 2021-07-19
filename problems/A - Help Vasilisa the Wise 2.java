import java.util.HashSet;
import java.util.Scanner;

public class Help_Vasilisa_the_Wise_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r1 = sc.nextInt();
        int r2 = sc.nextInt();
        int c1 = sc.nextInt();
        int c2 = sc.nextInt();
        int d1 = sc.nextInt();
        int d2 = sc.nextInt();


        int W = (c1 - r2 + d1) / (2);
        int Y = (c1 - r1 + d2) / (2);
        int X = (c2 - r2 + d2) / (2);
        int Z = (c2 - r1 + d1) / (2);

        HashSet<Integer> arr = new HashSet<Integer>();
        arr.add(W);
        arr.add(Y);
        arr.add(X);
        arr.add(Z);

        for (Integer i : arr) {
            if (i > 9 || i < 1) {
                System.out.println(-1);
                return;
            }
        }

        if (arr.size() == 4) {
            System.out.println(W + " " + X);
            System.out.println(Y + " " + Z);

        } else {
            System.out.println(-1);
        }

    }
}