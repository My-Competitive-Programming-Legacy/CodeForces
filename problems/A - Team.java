import java.util.Scanner;
public class Main
{
    public static void main (String []args)
    {
        int problems = 0,counter = 0;
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i = 1 ;i<=3*n ;i++)
        {
            int x = sc.nextInt();
            if(x == 1 )
                counter++;
            if(i%3 == 0 )
                {
                    if(counter>1)
                        problems ++;
                    counter = 0 ;     
                }
        }
        System.out.println(problems);
    }
}