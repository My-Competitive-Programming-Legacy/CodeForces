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
            while (q-- > 0) {
                int b = in.nextInt();
                int p = in.nextInt();
                int f = in.nextInt();
                int h = in.nextInt();
                int c = in.nextInt();
                if (2 * (p + f) <= b) {
                    out.println(h * p + c * f);
                } else {
                    int res = 0;
                    while (b >= 2) {
                        if (p > 0 && (h >= c || f == 0)) {
                            res += h;
                            p--;

                        } else if (f > 0 && (c >= h || p == 0)) {
                            res += c;
                            f--;

                        }
                        b -= 2;
                    }
                    out.println(res);

                }


            }
        }

    }
}
