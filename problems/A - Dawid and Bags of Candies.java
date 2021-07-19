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
    static final double E = 1e9;

    public static void main(String[] args) throws IOException {
       int[]arr = {sc.nextInt(),sc.nextInt(),sc.nextInt(),sc.nextInt()};
       Arrays.sort(arr);
       if(arr[0] + arr[3] == arr[1] + arr[2] || arr[3] == arr[0] + arr[1] + arr[2])
           System.out.println("YES");
       else
           System.out.println("NO");

    }

}