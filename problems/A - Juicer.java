import java.util.Scanner;

public class ShaassandOskols {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int b = sc.nextInt();
        int d = sc.nextInt();
        int res = 0;
        int sum =0;
        for(int i = 0 ;i<n ;i++)
        {
            int tmp =sc.nextInt();
            if(tmp <= b)
            {
                sum+=tmp;
            }
            if(sum > d)
            {
                res++;
                sum = 0;
            }
        }
        System.out.println(res);
        }
}