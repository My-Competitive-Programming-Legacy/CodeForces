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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            long arr[] = new long[n];
            arr[0] = in.nextLong();
            for (int i = 1; i < n; i++) {
                //arr[i] = in.nextInt();
                arr[i] = gcd(in.nextLong(), arr[i - 1]);
            }
            long res = 0;
            long target = arr[arr.length - 1];
            for (long j = 1; (j * j) <= target; j++) {
                if (arr[arr.length - 1] % j == 0) {
                    res++;
                    if (j * j != target)
                        res++;

                }
            }
            out.println(res);

        }

        static long gcd(long a, long b) {
            if (b == 0)
                return a;
            return gcd(b, a % b);

        }

    }
}
