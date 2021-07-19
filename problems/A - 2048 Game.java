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
    static FastReader sc = new FastReader();
    static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int q = sc.nextInt();
        while (q-- > 0) {
            int n = sc.nextInt();
            int[] arr = new int[100];
            for (int i = 0; i < n; i++) {
                int l =sc.nextInt();
                int t = (int) (Math.log(l)/Math.log(2));
                arr[t]++;
                int j = t;
                while (arr[j] == 2 && arr[11] == 0) {
                    arr[j] = 0;
                    arr[++j]++;
                    if(j>99)
                        break;
                }

            }
            if (arr[11] > 0) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}