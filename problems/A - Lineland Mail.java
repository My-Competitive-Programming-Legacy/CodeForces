import java.util.Scanner;

public class Lineland_Mail {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr  = new int[n] ;
        for(int i = 0 ;i<n;i++)
        {
            arr[i] = sc.nextInt();
        }

        for(int i = 0 ;i<n;i++)
        {
            int min,max;
            if(i ==0)
            {
                 min = arr[1] - arr[0];
                 max = arr[n-1] - arr[0];
            }else if (i+1 ==n)
            {
                min = arr[n-1] - arr[n-2];
                max = arr[n-1] - arr[0];

            }else
            {
                 min = Math.min(arr[i] - arr[i-1],arr[i+1]-arr[i]);
                 max = Math.max(arr[i] - arr[0]  ,arr[n-1]-arr[i]);
            }
            System.out.printf("%d %d\n",min,max);

        }
    }
}