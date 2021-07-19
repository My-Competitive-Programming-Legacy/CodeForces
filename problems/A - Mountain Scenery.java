import java.util.Scanner;

public class Mountain_Scenery {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = 2*sc.nextInt() +1;
        int k = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        for(int i = 0 ;i<n ;i++)
        {
            if(i%2 == 1 && n>(i+1) )
            {
                if((arr[i] - 1) >arr[i-1] && (arr[i] - 1) >arr[i+1] && k>0){
                    arr[i] = arr[i] - 1;
                    k--;
                }
            }
        }
        for(int i =0 ;i<n ;i++)
        {
            System.out.print(arr[i]+" ");
        }
    }
}