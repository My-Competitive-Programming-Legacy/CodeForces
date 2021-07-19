import java.util.ArrayList;
import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;

public class monMain {


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int nBuy, nSell, capital;
        nBuy = sc.nextInt();
        nSell = sc.nextInt();
        capital = sc.nextInt();
        int minBuy = 0;
        for (int i = 0; i < nBuy; i++) {
            int tmp = sc.nextInt();
            if(i == 0)
                minBuy = tmp;
            if (tmp < minBuy)
                minBuy = tmp;

        }
        int maxSell = 0;
        for (int i = 0; i < nSell; i++) {
            int tmp = sc.nextInt();
            if (tmp > maxSell)
                maxSell = tmp;
        }
        if (minBuy >= maxSell || minBuy > capital) {
            System.out.println(capital);
        } else {
            int n = capital / minBuy;
            System.out.println(capital - minBuy * n + maxSell * n);

        }


    }

}