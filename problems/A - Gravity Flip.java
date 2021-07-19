import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;
public class monMain {


        public static void main(String []args)
        {
            Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();
            Integer[] arr = new Integer[n];
            for(int i =0 ;i<n;i++)
            {
                arr[i] = sc.nextInt();
            }
            Arrays.sort(arr);

            for(int i = 0 ;i<n;i++)
            {
                System.out.print(arr[i]+" ");
            }
        }

}