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
      int n = sc.nextInt();
      int k = sc.nextInt();
      char[]arr = sc.nextLine().toCharArray();
      for (int i = 0 ;i<n && k>0;i++)
      {
          if(i == 0 && n!=1)
          {
              if(arr[i] != '1'){
                  arr[i] = '1';
                  k--;
              }
          }else
          {
              if(arr[i] != '0'){
                  arr[i] = '0';
                  k--;
              }
          }
      }
        for (int i = 0; i <n ; i++) {
            System.out.print(arr[i]);
        }

    }

}