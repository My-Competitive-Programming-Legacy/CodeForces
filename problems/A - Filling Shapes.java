import java.util.Scanner;

public class Filling_Shapes {
    public static void main(String[] args) {
        Scanner sc =  new Scanner(System.in);
        long n = sc.nextInt();
        System.out.println(n%2 == 1  ? 0: 1<<(n/2));
    }
}