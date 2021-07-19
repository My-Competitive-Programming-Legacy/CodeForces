import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;
public class monMain {


        public static void main(String []args)
        {
            Scanner sc = new Scanner(System.in);
            String  str1,str2;
            str1 = sc.nextLine();
            str2 = sc.nextLine();
            int ans =str1.compareToIgnoreCase(str2);
            if(ans == 0)
                System.out.println(0);
            else
                System.out.println(ans>0 ? 1:-1 );
        }

}