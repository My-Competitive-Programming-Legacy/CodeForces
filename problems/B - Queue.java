import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;
public class Queue {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] arr = new long[n];
        for(int i = 0 ;i<n ;i++)
        {
            arr[i] = sc.nextLong();
        }
        long tmp[] = new long[n];
        tmp[n-1] = arr[n-1];
 
        for(int i = arr.length-2 ;i>=0 ;i-- )
        {
            tmp[i] = Math.min(tmp[i+1] , arr[i]);
        }
        getLastMin(arr , tmp);
 
    }
 
    public static void getLastMin(long[] arr, long[] tmp) {
        for (int i = 0; i < arr.length-1; i++) {
            int l = i;
            int r = arr.length - 1;
            int res = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (tmp[mid] < arr[i]) {
                    l = mid+1 ;
                    res = mid ;
                } else {
                    r = mid - 1 ;
                }
            }
            if(res == -1)
            {
                System.out.print("-1 ");
            }else
                System.out.print(res - i-1 +" ");
        }
        System.out.println("-1");
        }
}