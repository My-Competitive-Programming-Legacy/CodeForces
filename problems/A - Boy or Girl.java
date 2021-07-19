import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;
public class monMain {


        public static void main(String []args)
        {

            Scanner sc = new Scanner(System.in);
            String  str1 = sc.nextLine();
            int counter = 0;
            int[] arr = new int[26];
            for(int i =0 ;i<str1.length();i++ )
            {
                arr[ str1.charAt(i)- 97] =1;
            }
            for(int i : arr)
            {
                if(i ==1)
                    counter++;
            }

            System.out.println(counter%2 == 1 ?  "IGNORE HIM!" :  "CHAT WITH HER!");


        }

}