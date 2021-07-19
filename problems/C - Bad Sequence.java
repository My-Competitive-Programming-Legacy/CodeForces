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
            in.nextLine();
            char[] arr = in.nextLine().toCharArray();
            int open = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] == '(')
                    open++;
                else
                    open--;

                if (open < -1) {
                    out.println("NO");
                    return;
                }
            }

            out.println((open == 0) ? "YES" : "NO");

        }

    }
}
