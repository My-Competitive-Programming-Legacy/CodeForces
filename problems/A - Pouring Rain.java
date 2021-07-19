import java.util.Scanner;

public class Pouring_Rain {
    public static void main(String[] args) {
        int d,h,v,e;
        Scanner sc = new Scanner(System.in);
        d = sc.nextInt();
        h = sc.nextInt();
        v = sc.nextInt();
        e = sc.nextInt();
          double  PI  = 3.14159265359;

        if(e >= (4*v)/ (PI*d*d))
            System.out.println("NO");
        else
        {
            System.out.println("YES");
            System.out.println((-1 * h)/((e)-((4*v)/(PI*d*d))));
        }
    }
}