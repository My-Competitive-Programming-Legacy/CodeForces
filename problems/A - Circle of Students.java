import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int q = in.nextInt();
            for (int i = 0; i < q; i++) {
                int n = in.nextInt();
                int minIndex = 0;
                int min = n + 1;
                int[] arr = new int[n];

                for (int j = 0; j < n; j++) {
                    arr[j] = in.nextInt();
                    if (arr[j] < min) {
                        min = arr[j];
                        minIndex = j;
                    }
                }

                if (go(arr, minIndex)) {
                    out.println("YES");
                } else
                    out.println("NO");
            }

        }

        boolean go(int[] arr, int j) {
            int i = j;
            boolean left = true;
            for (int s = 1; s < arr.length && left; s++) {
                int prev = (i - 1 > -1) ? i - 1 : arr.length - 1;
                if (arr[prev] < arr[i])
                    left = false;
                else
                    i = prev;
            }
            boolean right = true;
            i = j;
            for (int s = 1; s < arr.length && right; s++) {
                int next = (i + 1) % arr.length;
                if (arr[next] < arr[i++])
                    right = false;
                else
                    i = next;
            }

            return left || right;
        }

    }
}
