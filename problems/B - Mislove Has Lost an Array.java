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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int l = in.nextInt();
            int r = in.nextInt();

            long min = 0, max = 0;

            for (int i = 0; i < l; i++) {
                min += 1 << i;

            }
            min += (n - l);

            for (int i = 0; i < r; i++) {
                max += 1 << i;
            }
            max += (n - r) * 1 << (r - 1);

            out.println(min + " " + max);
        }

    }
}
