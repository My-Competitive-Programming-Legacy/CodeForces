import java.util.Scanner;

public class Given_Length_and_Sum_of_Digits {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int ss = sc.nextInt();
        int s = ss;
        if(s == 0 && m > 1 ) {
            System.out.println(-1 + " " + -1);
            return;
        }else if(s == 0 && m == 1 )
        {
            System.out.println(0 + " "+ 0);
            return;
        }
        String res = "";
        if ((m - 1) * 9 < (s)) {
            for (int i = m - 1; i > -1; i--) {
                res += Math.min(9, s);
                s -= Math.min(9, s);
            }
        }else
        {
            s--;
            for (int i = m - 2; i > -1; i--) {
                res += Math.min(9, s);
                s -= Math.min(9, s);
            }
            res+='1';
        }
        if(s!=0)
        {
            res = "1-";
        }

        // calc the max
        StringBuilder result = new StringBuilder(res);
        result.reverse();
        res = result.toString();
        System.out.print(res.replaceFirst("^0+(?!$)", "")  +" ");


        res = "";
        s = ss;
        for (int i = 0; i < m; i++) {
            //res += Math.min(Character.getNumericValue('9'),Integer.parseInt(s));
            res += Math.min(9, s);
            s -= Math.min(9, s);
        }
        if (s != 0 )
            res = "-1";
        System.out.print(res.replaceFirst("^0+(?!$)", ""));


    }
}