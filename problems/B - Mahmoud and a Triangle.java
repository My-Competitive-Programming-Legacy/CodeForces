import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Mahmoud_and_Triangle {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Integer[]arr = new Integer[n];
        for(int i = 0;i<n;i++)
        {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr , Collections.reverseOrder());
        for(int i = 0 ;i<n-2;i++)
        {
            if(arr[i] < (arr[i+1] +arr[i+2] ))
            {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("No");
    }
}