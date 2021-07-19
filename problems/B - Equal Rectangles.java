import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int q = in.nextInt();
            outer:
            for (int i = 0; i < q; i++) {
                int n = in.nextInt();
                int[] arr = new int[4 * n];
                for (int j = 0; j < arr.length; j++) {
                    arr[j] = in.nextInt();
                }
                Arrays.sort(arr);
                long res = arr[0] * arr[arr.length - 1];
                for (int l = 0, r = arr.length - 1; l + 1 < r - 1; l += 2, r -= 2) {
                    if (!((long) arr[l] * arr[r] == res && arr[l] == arr[l + 1] && arr[r] == arr[r - 1])) {
                        out.println("NO");
                        continue outer;
                    }
                }
                out.println("YES");


            }

        }

    }
}
