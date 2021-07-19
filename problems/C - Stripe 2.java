import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new PrintWriter(System.out));
        int n = Integer.parseInt(sc.readLine());
        String[] s = sc.readLine().split("\\s");
        int[] arr = new int[n];
        long[] prefix = new long[n];
        ArrayList<Integer> a = new ArrayList<>();
        ArrayList<Integer> b = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(s[i]);
            prefix[i] = arr[i];
            if (i > 0)
                prefix[i] += prefix[i - 1];
        }
        if(prefix[n-1] %3 !=0)
        {
            out.write("0" +  "\n");
            out.flush();
            return;
        }


        for (int i = 0; i <n ; i++) {
            if(prefix[i] == prefix[n-1] / 3)
                a.add(i);
            if (i<n-1 && prefix[i] == 2 * prefix[n-1] / 3)
                b.add(i+1);
        }
        long res = 0;
        for( int current : a)
        {
            int l  = 0;
            int r = b.size()- 1;
            int idx = b.size();
            while(l<=r)
            {
                int mid = l + (r - l)/2;
                if(b.get(mid) - current <= 1)
                {
                    l = mid+1;
                }else
                {
                    idx = mid;
                    r = mid-1;
                }
            }
            res+=b.size()-idx;
        }
        out.write(res +  "\n");
        out.flush();

    }
}