import java.util.Scanner;
public class Sum_of_Digits {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int res = 0;
        while (s.length() > 1) {
            int sum = 0;
            res++;
            for (int i = 0; i < s.length(); i++) {
                sum += Character.getNumericValue(s.charAt(i)); /// MAX is 900000
            }
            s = String.valueOf(sum);
        }
        System.out.println(res);
    }
}