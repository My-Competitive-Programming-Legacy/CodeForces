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
    static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
    static int MAX;
    static double E = 0.000000001;

    public static void main(String[] args) throws IOException {
        /**
         Scanner sc = new Scanner(new File("input.txt"));
         PrintWriter out = new PrintWriter("output.txt");
         out.flush(); // whether printWriter or bufferedWriter
         **/
        int n = sc.nextInt();
        char[] arr = sc.nextLine().toCharArray();
        int res = 0;
        for (int i = 0; i < n; i += 2) {
            if (arr[i] == arr[i + 1]) {
                arr[i] = 'a';
                arr[i+1] = 'b';
                res++;
            }

        }
        System.out.println(res);

        for (int i = 0; i <n ; i++) {
            System.out.print(arr[i]);
        }

    }
}