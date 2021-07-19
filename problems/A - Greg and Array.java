import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.*;

public class Greg_and_Array {
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

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        Integer n = sc.nextInt();
        Integer m = sc.nextInt(); // operations
        Integer k = sc.nextInt(); //    queries

        Integer[] input = new Integer[n];
        Long[] arr = new Long[n + 1];


        for (int i = 0; i < n; i++) {
            input[i] = (sc.nextInt());
            arr[i] = new Long(0);
        }
        arr[n] = new Long(0);

        operation[] o = new operation[m];
        for (int i = 0; i < m; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            int d = sc.nextInt();
            o[i] = new operation(l - 1, r - 1, d);
        }
        long q[] = new long[m+1];
        for (int i = 0; i < k; i++) {
            int x = sc.nextInt() - 1;
            int y = sc.nextInt() - 1;
            q[x]++;
            q[y+1]--;
        }
        o[0].edited = q[0] * o[0].d;
        for(int i = 1;i<q.length-1;i++)
        {
            q[i]+=q[i-1];
            //q[i] = q[i]/2 ;
            o[i].edited = q[i] * o[i].d;
        }

        for (int i = 0; i < o.length; i++) {
            arr[o[i].l] += o[i].edited;
            arr[o[i].r + 1] -= o[i].edited;
        }

        System.out.print(arr[0] + input[0] + " ");
        for (int i = 1; i < arr.length - 1; i++) {
            arr[i] += arr[i - 1];
            long res = arr[i] + input[i];
            System.out.print(res + " ");
        }
    }

    static class operation {
        Integer l;
        Integer r;
        Integer d;
        Long edited;

        operation(Integer l, Integer r, Integer d) {
            this.l = l;
            this.r = r;
            this.d = d;
            edited = new Long(0);
        }
    }


}