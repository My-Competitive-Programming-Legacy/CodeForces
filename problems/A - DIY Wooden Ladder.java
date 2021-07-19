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
            int n = in.nextInt();
            while (n-- > 0) {
                out.println(query(in));
            }

        }

        public static long query(Scanner in) {
            // long
            int n = in.nextInt();
            int max1 = 0, max2 = 0;
            for (int i = 0; i < n; i++) {
                int tmp = in.nextInt();
                if (tmp >= max1) {
                    max2 = max1;
                    max1 = tmp;
                    continue;
                }
                if (tmp > max2) {
                    max2 = tmp;
                }
            }
            long length = Math.min(max1, max2); // length of the minimum ladder hence we can obtain at most (length - 1) ladder

            if (length <= 0)
                return 0;
            return Math.min(n - 2, length - 1); // n>=2 :)


        }

    }
}
