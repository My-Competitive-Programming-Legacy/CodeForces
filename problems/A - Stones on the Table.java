import java.util.ArrayList;
import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;

public class monMain {
    public static void main(String []args)
    {
        Scanner sc = new Scanner (System.in);
        int n = sc.nextInt();
        int out = 0;
        String str = sc.next();
        for(int i = 0 ;i<n-1 ;i++)
        {
            if(str.charAt(i) ==str.charAt(i+1))
            {
                out++;
            }
        }
        System.out.println(out);




    }

}