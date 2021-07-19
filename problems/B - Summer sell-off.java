import java.util.Arrays;
import java.util.Scanner;

public class Summer_Sell_Off {
    static int type = 1;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[]arr = new int[n];
        long res  = 0;
        for(int i = 0 ;i<n;i++)
        {
            int x = sc.nextInt();
            int y = sc.nextInt();
            res+=Math.min(x,y);
            arr[i] = Math.min(2*x , y) - Math.min(x,y);
        }
        Arrays.sort(arr);
        for(int i = n-1;i>=0 && k>0;i--,k--)
        {
            res+=arr[i];
        }
        System.out.println(res);


    }



}