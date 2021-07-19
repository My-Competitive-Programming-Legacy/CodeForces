import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        sc.nextLine();
        String input = sc.nextLine();
        int[] valid = new int[26];
        String[] chars = sc.nextLine().split(" ");
        for (String s : chars) {
            int x = s.charAt(0) - 'a';
            valid[x] = 1;
        }
        StringBuilder regex = new StringBuilder("[");
        for (int i = 0; i < 26; i++) {
            if (valid[i] == 0) {
                regex.append((char) (i + 'a'));
            }
        }
        regex.append("]");
        if (regex.length() > 2) {
            String[] ok = input.split(regex.toString());
            long res = 0;
            for (String i : ok) {
                long len = i.length();
                res += len * (len + 1) / 2;
            }
            System.out.println(res);
        } else {
            System.out.println(((long) n * (n + 1)) / 2);
        }


    }
}