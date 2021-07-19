import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[]arr = new int[n] ;
        for(int i = 0 ;i<n;i++)
        {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        int res = 0;
        for (int i = 0; i <n ; i++) {
            if(arr[i] == -1)
                continue;
            res++;
            for (int j = i+1; j <n ; j++) {
                if(arr[j] % arr[i] == 0)
                    arr[j] = -1;
            }
        }
        System.out.println(res);
    }
}