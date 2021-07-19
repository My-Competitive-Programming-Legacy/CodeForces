//import java.io.BufferedReader;
//import java.io.InputStreamReader;
import java.util.Scanner;

public class FreeIceCream {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in) ;
       // BufferedReader sc2 = new BufferedReader (new InputStreamReader(System.in));
        long q,n=0,disteressed=0;
        //System.out.println(Integer.parseInt("+ 254".substring(2)));
        q = sc.nextInt();
        n = sc.nextInt();

        String  buffer = sc.nextLine();
        for(int i = 0 ; i<q;i++ )
        {
            String  s = sc.nextLine();
            if(s.charAt(0) == '+')
            {
                n+= Integer.parseInt(s.substring(2));
            }else
            {
                double tmp = Double.parseDouble(s.substring(2));
                if(n>=tmp)
                {
                    n-=tmp;
                }else
                {
                    disteressed++;
                }
            }
        }
        System.out.print(n+" ");
        System.out.print(disteressed);
    }
}