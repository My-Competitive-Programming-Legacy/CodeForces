import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;

public class monMain {


    public static void main(String[] args) {

        String word;
        int A = 0, D = 0;
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String buufer = sc.nextLine();
        word = sc.nextLine();
        for (int i = 0; i < word.length(); i++) {
            if (word.charAt(i) == 'A')
                A++;
            else
                D++;
        }
        if (A == D) {
            System.out.println("Friendship");
            return;
        }
        System.out.println(A > D ? "Anton" : "Danik");
            
    }

}