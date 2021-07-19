import java.lang.reflect.Array;
import java.util.*;

public class Oath_of_the_Nights_Watch {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        //ArrayList<Integer> arr = new ArrayList<Integer>();
        for(int i=0 ;i<n;i++)
        {
            arr[i] = (sc.nextInt());
        }
        Arrays.sort(arr);
        int min = arr[0];
        int max = arr[n-1];
        for(int i = 0,j = n-1 ;i<=j ;i++,j--  )
        {
            if(arr[i] > min & arr[j] <max){
                System.out.println(j-i+1);
                return;
            }

            if(arr[i] > min)
                i--;
            if(arr[j] <max)
                j++;
        }
        System.out.println(0);
    }
}