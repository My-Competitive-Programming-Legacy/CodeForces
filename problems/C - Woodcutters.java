import java.util.Scanner;

public class Woodcutters {
    static long[][] arr;
    static int n;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        arr = new long[n][2];

        for (int i = 0; i < n; i++) {
            arr[i][0] = sc.nextLong();
            arr[i][1] = sc.nextLong();
        }

        long last = arr[0][0];
        long res = 2;
        for (int i = 1; i < n-1; i++) {
            if (arr[i][0] - arr[i][1] > last) {
                
                res++;
                last = arr[i][0];
            } else if (arr[i][0] + arr[i][1] < arr[i + 1][0]) {
                last = arr[i][0] + arr[i][1];
                res++;
            } else {
                last = arr[i][0]; // skip
            }
        }
        System.out.println(n == 1 ? 1:res);
    }
}