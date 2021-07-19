import java.util.*;
import java.io.*;
 
public class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }
 
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
 
        double nextDouble() {
            return Double.parseDouble(next());
        }
 
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
 
    static FastReader sc = new FastReader();
    public static void main(String[] args) throws IOException {
        int n = sc.nextInt();
        if (n == 2) {
            long a = sc.nextInt();
            long b = sc.nextInt();
            System.out.println(1 + " " + Math.abs(a - b));
            return;
        }
        long[] arr = new long[n];
        long max = Long.MIN_VALUE;
        long min = Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            max = Math.max(max, arr[i]);
        }
        long gcd = 0;
        long res = 0;
        for (int i = 0; i < n; i++) {
            gcd = gcd(gcd , max - arr[i]);
            res += (max - arr[i]);
        }
          
 
        System.out.println(res / gcd + " " + gcd);
 
    }
 
    static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
 
    }
 
 
}