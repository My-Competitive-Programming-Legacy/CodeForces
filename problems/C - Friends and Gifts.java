import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.LinkedList;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Hamza
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
            int[] freq = new int[n + 1];
            int[] arr = new int[n + 1];

            for (int i = 1; i <= n; i++) {
                int a = in.nextInt();
                arr[i] = a;
                freq[a] = 1;
            }
            LinkedList<Integer> ok = new LinkedList<>();
            for (int i = 1; i <= n; i++) {
                if (freq[i] == 0) ok.add(i);
            }
            int[] print = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                int res = arr[i];
                if (arr[i] == 0) {
                    if (ok.getLast() == i) res = ok.removeFirst();
                    else {
                        res = ok.removeLast();
                    }
                }
                print[i] = res;

            }
            for (int j = 1; j <= n; j++) {
                if (print[j] == j) {
                    int idx = j;
                    for (int i = 1; i <= n; i++) {
                        if (arr[i] == 0) {
                            int t = print[idx];
                            print[idx] = print[i];
                            print[i] = t;

                        }
                    }
                }
            }
            for (int i = 1; i <= n; i++) {
                out.print(print[i] + " ");
            }
        }

    }
}
