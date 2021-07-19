import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Chat_Online {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Set<Integer> res = new HashSet<Integer>();

        int p = sc.nextInt();
        int q = sc.nextInt();
        int l = sc.nextInt();
        int r = sc.nextInt();
        int[] arr = new int[10000];
        for (int i = 0; i < p; i++) {
            arr[sc.nextInt()] = 1;
            arr[sc.nextInt() + 1] = -1;

        }
        for (int i = 1; i < arr.length; i++) {
            arr[i] += arr[i - 1];
        }
        for (int i = 1; i < arr.length; i++) {
            arr[i] += arr[i - 1];
        }

        for (int i = 0; i < q; i++) {
            int L = sc.nextInt();
            int R = sc.nextInt();
            for (int j = l; j <= r; j++) {
                if ((L + j - 1) >= 0) {
                    if (arr[R + j] - arr[L - 1 + j] > 0)
                        res.add(j);
                } else if (arr[R + j] > 0)
                    res.add(j);
            }
        }
        System.out.println(res.size());
    }
}