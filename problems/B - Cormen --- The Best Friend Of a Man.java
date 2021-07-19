import java.util.Scanner;

public class Cormen_The_Best_Friend_Of_a_Man {
    public static void main(String[] args) {
        Scanner sc =  new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[]arr = new int[n];
        for (int i = 0; i <n ; i++) {
            arr[i] = sc.nextInt();
        }
        int res =0;
        for(int i = 1;i<n;i++)
        {
            int t = arr[i];
            arr[i] += Math.max(0 , k - (arr[i] + arr[i-1]));
            res+=arr[i] - t;
        }
        System.out.println(res);
        for (int i = 0; i <n ; i++) {
            System.out.print(arr[i]+" ");
        }
    }
}