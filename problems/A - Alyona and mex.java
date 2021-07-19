import java.util.Scanner;

public class Alyona_and_mex {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int mex= n;
        for(int i =0 ;i<k;i++)
        {
            subSegment tmp  = new subSegment(sc.nextInt()-1,sc.nextInt()-1) ;
            if((tmp.r - tmp.l + 1)<mex)
            {
                mex = tmp.r - tmp.l + 1;
            }
        }
        System.out.println(mex);
        for(int i = 0 ;i<n;i++)
        {
            System.out.print(i%mex+" ");
        }
    }
    static  class subSegment
    {
        int l;
        int r;
        subSegment(int a , int b)
        {
            l = a;
            r = b;
        }
    }
}