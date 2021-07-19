import java.awt.*;
import java.io.*;
import java.util.HashSet;
import java.util.Iterator;
import java.util.StringTokenizer;

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

    public static void main(String[] args) throws IOException {
        FastReader sc = new FastReader();
        //BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        long a = sc.nextInt();
        long b = sc.nextInt();
        long c = sc.nextInt();
        long res = 0;
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                for (int k = 1; k <= c; k++) {
                    res+= countDivisors(i*j*k) % 1073741824 ;
                }
            }
        }
        System.out.println(res);
    }

    static long dp[] = new long[1000001];
    static long countDivisors(int a)
    {
        if(dp[a] != 0)
            return dp[a];
        long res = 0;
        for (int i = 1; i*i <=a ; i++) {
            if(a%i == 0)
                res+=2;
            if(i*i == a)
                res-=1;
        }
        return dp[a] = res ;
    }




}