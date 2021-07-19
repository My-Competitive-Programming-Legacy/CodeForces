import java.util.Arrays;
import java.util.Scanner;

public class Olympic_Medal {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[]arr1 = new int[n];
        for(int i = 0;i<n;i++)
        {
            arr1[i] = sc.nextInt();
        }
        Arrays.sort(arr1);
        int r1 = arr1[arr1.length-1];


         n = sc.nextInt();
        int[]arr = new int[n];
        for(int i = 0;i<n;i++)
        {
            arr[i] = sc.nextInt();
        }

         n = sc.nextInt();
        int[]arr2 = new int[n];
        for(int i = 0;i<n;i++)
        {
           arr2[i] = sc.nextInt();
        }
        Arrays.sort(arr2);

        int a = sc.nextInt();
        int b = sc.nextInt();

        int p2 = arr2[0];
        double factor = -1;
        for(int i = 0;i<arr.length;i++)
        {
            double tmp  = (b*arr[i])/(double)(a*p2 + b*arr[i]) ;
            factor = Math.max(tmp , factor);
        }
        System.out.println(Math.sqrt(factor * r1 * r1));

    }
}