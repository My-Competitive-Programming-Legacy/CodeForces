import java.util.Scanner;

public class Joysticks {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int res = 0;
        while (true) {
            if (a == 0 || b == 0 || (a == 1 && b == 1))
                break;

            int c1 = Math.min(a, b);
            int c2 = Math.max(a, b);
            c1 += 1;
            c2 -= 2;
            a = c1;
            b = c2;
            res++;
        }
        System.out.println(res);

    }
}