import java.util.Scanner;

public class Easter_Eggs {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = "ROYGBIV";
        String s2 = "GBIV";
        int ptr = 0; //green
        int n = sc.nextInt();
        for (int i = 0; i < n; ) {
            if (i < 7)
                System.out.print(s.charAt(i++));
            else {
                for (int j = ptr;i < n; i++, j = (j+1)%4) {
                    System.out.print(s2.charAt(j));
                }

                ptr = Math.abs((ptr +1) % 4);
            }
        }
    }

}