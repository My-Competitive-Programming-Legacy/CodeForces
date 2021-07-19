import java.util.Scanner;
public class  Main 
{
    public static void main(String []args)
    {
        int n = 0;
        int a,b ; //inputs
        Scanner sc = new Scanner(System.in);
        a= sc.nextInt();
        b= sc.nextInt();
        while(a<=b)
        {
            a = 3*a;
            b =2*b;
            n++;
        }
        System.out.println(n);
    }
    
}