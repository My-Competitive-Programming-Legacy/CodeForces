
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Hamza {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String road , instructions;
        road = sc.nextLine();
        instructions = sc.nextLine();
        int j  =0;
        for (int i = 0 ;i<instructions.length() ;i++)
        {
            if(road.charAt(j) == instructions.charAt(i))
                j++;
        }
        System.out.println(j+1);
       }




    }