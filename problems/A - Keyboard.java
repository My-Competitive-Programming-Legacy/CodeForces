import java.util.Scanner;

public class Keyboard {
    public static void main(String[] args) {


    Scanner sc = new Scanner(System.in);
    String ref = "qwertyuiopasdfghjkl;zxcvbnm,./";
    char d = sc.nextLine().charAt(0);
    String input = sc.nextLine();
    char[] tmp = input.toCharArray();;

    for(int i=0 ;i<input.length();i++ )
    {

        char tmp1 =input.charAt(i);
        char tmp2;
        if(d == 'R')
            tmp[i] = ref.charAt(ref.indexOf(tmp1)-1);
        else
            tmp[i] = ref.charAt(ref.indexOf(tmp1)+1);

    }
        for(char i : tmp)
            System.out.print(i);
    }
}