import java.util.Scanner;
 
public class NewPassword {
    public static void main(String[] args) {
        String total = "abcdefghijklmnopqrstuvwxyz";
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        String result="" ;
       //result += total.substring(0,);
        while (result.length() < n)
        {
            result += total.substring(0,k);
        }
        result = result.substring(0,n);
        System.out.println(result);
        //System.out.println("abABA".substring(0,4));
    }
}