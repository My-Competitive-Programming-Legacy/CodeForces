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
        HashSet<Point> hs = new HashSet<Point>();
        //xa, ya, xb, yb
        int xa = sc.nextInt();
        int ya = sc.nextInt();
        int xb = sc.nextInt();
        int yb = sc.nextInt();

        for (int i = Math.min(ya, yb); i <= Math.max(ya, yb); i++) {
            hs.add(new Point(xa, i));
            hs.add(new Point(xb, i));
        }

        for (int i = Math.min(xa, xb); i <= Math.max(xa, xb); i++) {
            hs.add(new Point(i, ya));
            hs.add(new Point(i, yb));
        }

        int n = sc.nextInt();
        while(n-- > 0)
        {
            int a  = sc.nextInt();
            int b  = sc.nextInt();
            int r  = sc.nextInt();
            Iterator<Point> itr = hs.iterator();
            while (itr.hasNext())
            {
                Point p = itr.next();
                if((p.x - a)*(p.x - a) + (p.y - b)*(p.y - b) <= r*r)
                {
                    itr.remove();
                }
            }
        }
        System.out.println(hs.size());

    }


}