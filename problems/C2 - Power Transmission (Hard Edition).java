import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Power_Transmission {
    static final double E = 0.0000001;
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }
        short nextShort()
        {
            return Short.parseShort(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }

    public  static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    public static void main(String[] args) {


        FastReader sc = new FastReader();
        int n = sc.nextInt();
        short[] x = new short[n];
        short[] y = new short[n];

        for (int i = 0; i < n; i++) {
            x[i] = sc.nextShort();
            y[i] = sc.nextShort();
        }

        TreeSet<line> arr = new TreeSet<line>();
        for (int i = 0; i < x.length; i++) {
            for (int j = i + 1; j < x.length; j++) {
                if(arr.add(new line(x[i], y[i], x[j], y[j])))
                {

                }else
                {
                   //System.out.printf("Sorry (%d,%d) and (%d,%d) ",x[i],y[i],x[j],y[j]);
                }
            }
        }

        line arr2[] = arr.toArray(new line[arr.size()]);
        long cnt = 0;
        for(int i =0;i<arr.size();i++)
        {
            int j;
            for( j = i+1 ;j<arr.size()  ;j++)
            {
                if(arr2[i].a == arr2[j].a && arr2[i].b == arr2[j].b)
                    cnt++;
                else
                {
                    break;
                }
            }
        }
        long l = arr.size();
        System.out.println(l*(l-1)/2 - cnt);
    }

    static class line implements Comparable<line>{

        int a;
        int b;
        double c;
        line(short x1, short y1, short x2, short y2) {
            a = y2 - y1;
            b = x1 - x2;

            if(b!=0)
                c = y1 - x1*((-1*a)/(double)(b));
            else {
                c = x1;
                a = 1;
                b = 0;
            }

            int g = gcd(a,b);
            a = a/g;
            b = b/g;
        }
        @Override
        public int hashCode() {
            double x = Double.parseDouble(String.format("%.4f",c));
           return Objects.hash(a,b,x);
        }
        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            line other = (line) o;

            return (this.a == other.a) &&Math.abs(this.c - other.c) < E&& (this.b == other.b);
        }
        @Override
        public int compareTo(line other )
        {
            if((this.a == other.a) &&Math.abs(this.c - other.c) < E&& (this.b == other.b))
                return 0;
            else if((this.a == other.a) &&(this.b == other.b))
            {
                return Double.compare(this.c , other.c);
            }else if(this.a == other.a)
            {
                return Integer.compare(this.b , other.b) ;
            }else
                return Integer.compare(this.a , other.a) ;
        }
    }

}