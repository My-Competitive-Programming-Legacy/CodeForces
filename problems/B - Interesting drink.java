import java.util.Arrays;
import java.util.Scanner;

public class Interesting_drink {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Integer[]arr = new Integer[n];
        for (int i = 0; i <n ; i++) {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        int q = sc.nextInt();
        while(q-- > 0 )
        {
            int t = sc.nextInt();
            int l = 0;
            int r = n-1;

            int idx = -1;
            while (l<=r)
            {
                int mid = l + (r-l)/2 ;
                if(arr[mid] <= t )
                {
                    idx = mid;
                    l = mid+1;
                }else
                {
                    r = mid-1;
                }
            }
            System.out.println(idx+1);
        }
    }
}