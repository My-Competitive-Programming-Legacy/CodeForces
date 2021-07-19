import java.util.Scanner;
import java.lang.*;
public class MAIN{
    public static void main(String []args)
    {
        int x=0,y=0;
        Scanner sc  = new Scanner(System.in);
        for(int i = 0 ;i<5 ;i++)
        {
            for(int j = 0 ;j<5 ;j++ )
            {
                int tmp = sc.nextInt();
                if(tmp == 1 )
                {
                    x = i;
                    y = j; 
                }
            }
        }
        System.out.println(Math.abs(x-2) + Math.abs(y-2));
    }
    
    
}