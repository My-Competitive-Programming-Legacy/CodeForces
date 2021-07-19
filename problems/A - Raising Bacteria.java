import java.util.Scanner;

public class Raising_Bacteria {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
       // System.out.println(nearestPowerOfTwo(18));
        int n = sc.nextInt();
        System.out.println(days(n));



    }

    public static long days(long n) {
        long powerOfTwo = (n & (n - 1));
        if(n ==0)
            return 0;
        else if ((powerOfTwo == 0 && n > 0)|| n ==1) {
            return 1;
        } else {
             return 1+days(n - nearestPowerOfTwo(n) );
        }
    }

    public static long nearestPowerOfTwo(long n) {
        int res = 0;
        while (n >> 1 != 0) {
            res++;
            n = n >> 1;
        }
        return 1 << res;
    }
}