import java.util.Scanner;
 
public class Maximum_of_Maximums_of_Minimums {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        long first = 0, last = 0, min = 1000000000, max = -1000000000;
        for (int i = 0; i < n; i++) {
            long tmp = sc.nextInt();
            if (i == 0)
                first = tmp;
            else if (i == n-1)
                last = tmp;
 
 
                if (tmp < min)
                    min = tmp;
                 if (tmp > max)
                    max = tmp;
 
        }
        if (k == 1) {
            System.out.println(min);
 
 
        } else if (k == 2) {
            System.out.println(Math.max(first,last));
        } else {
            System.out.println(max);
        }
    }
}