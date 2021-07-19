import java.io.*;
import java.text.Format;
import java.util.*;

public class Main {
    static BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
    //static BufferedReader sc;
//    static {
//        try {
//            sc = new BufferedReader(new FileReader("in.txt"));
//        } catch (FileNotFoundException e) {
//            e.printStackTrace();
//        }
//    }

    public static void main(String[] args) throws IOException {

        int q = Integer.parseInt(sc.readLine());

        while(q-- > 0) {
           int n =readInt();
           Integer []arr = readArray(n);
           Arrays.sort(arr);
           int res = 0;
            for (int i = n; i >=0 ; i--) {
                if(arr[n-i]>=i )
                {
                    res = i;
                    break;
                }

            }
            System.out.println(res );

        }
    }
    static class Point implements Comparable<Point> {
        int x, y, i;

        public Point(int x, int y, int i) {
            this.x = x;
            this.y = y;
            this.i = i;
        }

        @Override
        public int compareTo(Point o) {
            if (x != o.x)
                return x < o.x ? 0 : 1;
            else
                return y < o.y ? 0 : 1;

        }
    }


    static long readLong() throws IOException {

        return Long.parseLong(sc.readLine());
    }

    static int readInt() throws IOException {

        return Integer.parseInt(sc.readLine());
    }

    static String readLine() throws IOException {
        return sc.readLine();
    }

    static Integer[] readArray(int n) throws IOException {
        String[] s = sc.readLine().split(" ");
        Integer[] arr = new Integer[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(s[i]);
        }
        return arr;
    }



}