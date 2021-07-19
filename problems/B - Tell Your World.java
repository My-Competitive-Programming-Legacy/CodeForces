import java.util.*;

public class Tell_Your_World {
    static final double E = 0.0000001;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[n + 1];
        for (int i = 1; i <= n; i++)
            arr[i] = sc.nextInt();

        boolean thereIsAnswer = false;
        outer:
        for (int i = 1; i < 4; i++) {
            for (int j = i; j < 4; j++) {
                if (j == i)
                    continue;

                line src = new line(i, arr[i], j, arr[j]);
                for (int k = 1; k <= n; k++) {

                    line other = src.getParallel(k, arr[k]);


                    for(int l = 1 ;l<=n &&!other.identical(src) ;l++)
                    {
                        if((src.passThroughPoint(l,arr[l]) ||  other.passThroughPoint(l,arr[l])))
                        {
                            thereIsAnswer = true;
                        }else
                        {
                            thereIsAnswer = false;
                            break ;

                        }
                    }
                    if(thereIsAnswer && !other.identical(src))
                        break outer;

                }


            }
        }
        System.out.println(thereIsAnswer ? "YES" : "NO");


    }

    public static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static class line implements Comparable<line> {

        int a;
        int b; // b = 1 always
        double c;

        line(int x1, int y1, int x2, int y2) {
            a = y1 - y2;
            b = x2 - x1;

            if (b != 0)
                c = (x1*(y2 - y1) - y1*(x2 - x1));
            else {
                c = -1 *x1;
                a = 1;
                b = 0;
            }

        }


        line(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        @Override
        public int hashCode() {
            double x = Double.parseDouble(String.format("%.4f", c));
            return Objects.hash(a, b, x);
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            line other = (line) o;

            return (this.a == other.a) && Math.abs(this.c - other.c) < E && (this.b == other.b);
        }

        @Override
        public int compareTo(line other) {
            if ((this.a == other.a) && Math.abs(this.c - other.c) < E && (this.b == other.b))
                return 0;
            else if ((this.a == other.a) && (this.b == other.b)) {
                return Double.compare(this.c, other.c);
            } else if (this.a == other.a) {
                return Integer.compare(this.b, other.b);
            } else
                return Integer.compare(this.a, other.a);
        }

        @Override
        public String toString() {
            return String.format("equation is %dX + %dY + %.2f = 0\n", a, b, c);
        }


        public line getParallel(int x, int y) {

            return new line(a, b, -1*(a * x + b * y));
        }


        public boolean passThroughPoint(int x, int y) {
            return Math.abs(a * x + b * y + c) < E;
        }


        public boolean parallel(line o) {
            return ((b == 0 && o.b == 0) || Math.abs(a / (double) b - o.a / (double) o.b) < E);
        }


        public boolean identical(line o) {
            double d1 = gcd(a, b);
            double d2 = gcd(o.a, o.b);
            return parallel(o) && Math.abs(c / d1 - o.c / d2) < E;
        }
    }

}
