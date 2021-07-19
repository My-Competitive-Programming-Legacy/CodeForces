import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
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

                int a = in.nextInt();
                int b = in.nextInt();
                int n = in.nextInt() % 3;
                if (n == 0)
                    System.out.println(a);
                else if (n == 1)
                    System.out.println(b);
                else
                    System.out.println(a ^ b);
            }
        }

    }
}
