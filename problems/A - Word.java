import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;
public class monMain {


        public static void main(String []args)
        {
            int nl = 0 , ul = 0; // number of uppercase letters and lowercase letters
            String word;
            Scanner sc = new Scanner(System.in);
            word = sc.nextLine();
            for(int  i = 0 ; i<word.length();i++)
            {
                if(Character.isUpperCase(word.charAt(i)))
                    ul++;
                else
                    nl++;

            }
            if(ul>nl)
                System.out.println(word.toUpperCase());
            else
                System.out.println(word.toLowerCase());
        }

}