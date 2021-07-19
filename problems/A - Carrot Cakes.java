import java.util.ArrayList;
import java.util.Scanner;
public class CarrotCakes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();
        int k = sc.nextInt();
        int d = sc.nextInt();
        if(k>=n)
            System.out.println("NO");
        else
        {
            if((t*(((int)Math.ceil((double) n/k))) - d) <=t)
                System.out.println("No");
            else
                System.out.println("YES");

        }
        //System.out.println(Math.ceil(599.0/54));




    }

}