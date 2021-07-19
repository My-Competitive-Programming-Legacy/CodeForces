import java.util.Scanner;

public class Translation {
    public static void main(String[] args) {
        Scanner sc=  new Scanner(System.in);
        String  a = sc.nextLine();
        String  b = sc.nextLine();
        StringBuilder sb = new StringBuilder(b);

        System.out.println(a.equals(sb.reverse().toString()) ? "YES":"NO" );
    }
}