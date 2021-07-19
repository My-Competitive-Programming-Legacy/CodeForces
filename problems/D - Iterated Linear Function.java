import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Hamza Hassan
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        static final long MOD = (long) 1e9 + 7;

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            long a = in.nextLong();
            long b = in.nextLong();
            long n = in.nextLong();
            long x = in.nextLong();
            long e = fastPower(a, n);
            if (a == 1) {
                out.println((x + (n % MOD * b) % MOD)%MOD);
            } else {
                long multiplicativeInverse = fastPower(a - 1, MOD - 2);
                long geometric = ((multiplicativeInverse % MOD * (e - 1)) % MOD) % MOD;
                out.println(((e * x) % MOD + (b * geometric) % MOD) % MOD);
            }
        }

        static long fastPower(long n, long a) {
            if (a == 0) {
                return 1;
            } else if (a == 1) {
                return n;
            } else if (a % 2 == 0) {
                long half = fastPower(n, a / 2) % MOD;
                return ((half * half) % MOD);

            } else {
                return (n * (fastPower(n, a - 1) % MOD)) % MOD;
            }
        }

    }
}
