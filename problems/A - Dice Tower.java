import java.util.Scanner;

public class Dice_Tower {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int  n = sc.nextInt();
        int top = sc.nextInt();
        for(int i = 0 ;i<2*n ;i++ )
        {
            int tmp = sc.nextInt();
            if(tmp == top || (7-tmp)== top )
            {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");

    }
}