import java.awt.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Growing_Mushrooms {
    static double E =0.000000001;
    public static void main(String[] args) {
        ArrayList<pair> arr = new ArrayList<pair>();
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t1 = sc.nextInt();
        int t2 = sc.nextInt();
        int k = 100 - sc.nextInt();

        for(int i = 1;i<=n;i++)
        {
            int a =sc.nextInt();
            int b =sc.nextInt();
            double res1 = a*t1*(k/100.0) + t2*b;
            double res2 = b*t1*(k/100.0) + t2*a;
            //System.out.printf("%d %.2f\n",i,Math.max(res1,res2));
            arr.add(new pair(i,Math.max(res1,res2)));
        }
        Collections.sort(arr);
        for(pair i : arr)
        {
            System.out.printf("%d %.2f\n",i.i,i.a);
        }
    }
    static class pair implements Comparable<pair>
    {
        double a ;
        int i;
        pair(int i , double d)
        {
            this.i= i;
            a = Double.parseDouble( String.format("%.2f",d));
        }
        public int compareTo(pair o)
        {
            if((a == o.a))
            {
                return Integer.compare(this.i, o.i);
            }else
                return Double.compare(o.a , this.a);
        }

    }
}