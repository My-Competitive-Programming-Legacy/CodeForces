import java.util.Scanner;

public class Olesya_and_Rodion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        if(k == 10)
            k = 1;
        if(k == 1 && n==1)
        {
            System.out.println(-1);
            return;
        }

        System.out.print(k);
        for(int i =0 ;i<n-1 ;i++ )
        {
            System.out.print(0);
        }
    }
}