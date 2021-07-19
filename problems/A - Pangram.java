import java.util.Scanner;

public class Pangram {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        String buffer = sc.nextLine();
        String s = sc.nextLine();
        int arr[] = new int[26];
        s = s.toLowerCase();
        for (int i = 0; i < s.length(); i++) {
            arr[s.charAt(i) - 'a'] = 1;
        }

        for (int i : arr) {
            if (i == 0) {
                System.out.println("NO");
                return;
            }
        }

        System.out.println("YES");
    }

}