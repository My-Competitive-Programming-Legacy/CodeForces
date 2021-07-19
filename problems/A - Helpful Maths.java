import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class HelpfulMaths {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String in = sc.nextLine().replaceAll("\\+","");
        Integer[] arr = new Integer[in.length()];
        for(int i = 0, k=0 ;i<in.length();i++)
        {
                arr[k++] = Character.getNumericValue(in.charAt(i));
        }
        Arrays.sort(arr);
        for(int i= 0 ;i<arr.length-1;i++ )
        {
            System.out.print(arr[i]+"+");
        }
        System.out.println(arr[arr.length-1]);






    }
}