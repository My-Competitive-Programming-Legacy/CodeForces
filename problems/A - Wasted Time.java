import java.awt.*;
import java.util.Scanner;

public class Wasted_Time {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt() -1;
        int k = sc.nextInt();
        Point p1 = new Point(sc.nextInt(),sc.nextInt());
        //Point p = new Point();
        double total = 0;
        while(n-- >0)
        {
            Point tmp = new Point(sc.nextInt(),sc.nextInt()) ;
            total += tmp.distance(p1);
           // System.out.println(total);
            p1.x = tmp.x;
            p1.y = tmp.y;
        }
        System.out.println((total/50.0) * k );

    }
}