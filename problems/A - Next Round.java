import java.util.Scanner;

public class Next_Round {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n  = sc.nextInt();
        int k = sc.nextInt();
        int cnt = 0;
        int ref = 0;
        int[] arr = new int[n];
        for(int i = 0 ;i<n;i++)
        {
           arr[i] =  sc.nextInt();
           if(i==(k-1))
               ref = arr[i];

        }
        for(int i = 0 ;i<n;i++){
            if(arr[i] >= ref && arr[i] >0)
                cnt++;
            else
                break;
        }
        System.out.println(cnt);
    }
}