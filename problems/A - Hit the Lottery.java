

import java.util.Scanner;

public class Hit_the_Lottery {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        int[]arr = {100,20,10,5};
        int res = 0;
        for(int $ : arr)
        {
            if((n - n%$)/$ < 0)
                continue;
            res+= (n - n%$)/$;
            n = n%$;
        }
        System.out.println(res+n);


    }
}