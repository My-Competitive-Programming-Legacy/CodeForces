import java.util.Scanner;

public class Valera_and_X {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String buffer  = sc.nextLine();
        String s  = sc.nextLine();
        char x = s.charAt(0); // the character which forms the X shape
        char o = s.charAt(1); // the other character
        boolean flag = x==o ? false : true;
        int line = 0;
       for(int j = 0 ;j<n ;j++)
       {
           for(int i =0 ;i<n && flag == true ;i++)
           {
               if(i == line || i == (n-line-1) )
               {

                   if(!(s.charAt(i) == x))
                       flag = false;

               }else
               {
                   if(s.charAt(i) !=o)
                       flag = false;
               }
           }
           line++;

           if(j<n-1)
                s  = sc.nextLine();
       }
        System.out.println(flag == true ? "YES":"NO");
    }
}