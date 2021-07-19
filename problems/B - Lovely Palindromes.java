//package Div2_B;

import java.util.LinkedList;
import java.util.Scanner;

public class Lovely_Palindromes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        LinkedList<Character> arr = new LinkedList<Character>();
        int i = s.length()-1;
        while (i>=0)
        {
            arr.addFirst(s.charAt(i));
            arr.add(s.charAt(i--));
        }
        for(Character c : arr)
        {
            System.out.print(c);
        }
        System.out.println();
    }
}