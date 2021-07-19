import java.util.Scanner;

public class Hamza {
    public static void main(String args[])
    {
        int m, n, sum = 0;
        Scanner s = new Scanner(System.in);
        m = s.nextInt();

        System.out.println(find(m));
    }
    public static int find (int x)
    {
        int m = x ;
        int sum=0;
        int n = 0;
        while(m > 0)
        {
            n = m % 10;
            sum = sum + n;
            m = m / 10;
        }
        if(sum %4 == 0)
            return x ;
        else
                return find(x+1) ;
    }

}