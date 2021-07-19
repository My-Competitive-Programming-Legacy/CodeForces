import java.util.Scanner;

public class Steps {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long m = sc.nextLong();
        long xi = sc.nextLong();
        long yi = sc.nextLong();
        int q = sc.nextInt();
        long steps = 0;
        while (q-- > 0) {
            long dx = sc.nextLong();
            long dy = sc.nextLong();
            long kx , ky;
            if(dx ==0)
                kx = Long.MAX_VALUE;
            else if(dx < 0)
                kx = (1-xi)/dx ;
            else
                kx = (n - xi)/dx ;

            if(dy ==0)
                ky = Long.MAX_VALUE;
            else if(dy < 0)
                ky = (1-yi)/dy ;
            else
                ky = (m - yi)/dy ;

            long k = Math.min(kx , ky);

            steps += k;
            xi = xi + dx * k;
            yi = yi + dy * k;
        }
        System.out.println(steps);
    }
}